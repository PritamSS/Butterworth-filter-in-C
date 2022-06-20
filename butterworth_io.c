#include<stdio.h>
#include <math.h>
#include <time.h>
#define Rand_Max 3267
#define signal_size 5001


double rand_0_1(void)
{
    return rand() / (double) Rand_Max;
}



void ButterworthLowpassFilter0050SixthOrder(const double src[], double dest[], int size)
{
    const int NZEROS = 6;
    const int NPOLES = 6;
    const double GAIN = 1.165969038e+05;

    double xv[7] = {0.0}, yv[7] = {0.0};

    for (int i = 0; i < size; i++)
    {
        xv[0] = xv[1]; xv[1] = xv[2]; xv[2] = xv[3]; xv[3] = xv[4]; xv[4] = xv[5]; xv[5] = xv[6];
        xv[6] = src[i] / GAIN;
        yv[0] = yv[1]; yv[1] = yv[2]; yv[2] = yv[3]; yv[3] = yv[4]; yv[4] = yv[5]; yv[5] = yv[6];
        yv[6] =   (xv[0] + xv[6]) + 6.0 * (xv[1] + xv[5]) + 15.0 * (xv[2] + xv[4])
                     + 20.0 * xv[3]
                     + ( -0.2951724313 * yv[0]) + (  2.1290387500 * yv[1])
                     + ( -6.4411118810 * yv[2]) + ( 10.4690788930 * yv[3])
                     + ( -9.6495177287 * yv[4]) + (  4.7871354989 * yv[5]);
        dest[i] = yv[6];
    }
}

main()
{
    double i, z, m, random_value, amplitude, amp_ranged;
    double time_period = 5;
    double dt = 0.001;
    double time_array[signal_size], noisy_signal[signal_size], filtered_signal[signal_size], signal[signal_size];
    double x,y, u=0;
    int k;

    printf("enter the amplitude: ");
    scanf("%lf", &amplitude);

    int j = 0;

     for(i = 0; i<signal_size; i++)
     {
       time_array[j] = i*dt;
       j++;
     }

     amp_ranged = amplitude/3;

    for (k=0;k<signal_size;  k=k+1)
    {
        z = 2*M_PI*1*time_array[k];
        signal[k] = amplitude*sin(z);
        random_value = amp_ranged*(rand_0_1()/10);
        noisy_signal[k] = signal[k] + random_value;
    }

    ButterworthLowpassFilter0050SixthOrder(noisy_signal, filtered_signal, 5001);

    FILE *fp=NULL;
    fp=fopen("sine2.txt","w");

    for(k=0; k<signal_size; k=k+1){
    x=time_array[k];
    y=signal[k];
    fprintf(fp,"%lf\t %lf\n",x,y);
  }


      FILE *fp2=NULL;
    fp2=fopen("noisy_signal2.txt","w");

    for(k=0; k<signal_size;  k=k+1){
    x=time_array[k];
    y=noisy_signal[k];
    fprintf(fp2,"%lf\t %lf\n",x,y);
  }

        FILE *fp3=NULL;
    fp3=fopen("filtered_signal2.txt","w");

    for(k=0; k<signal_size; k=k+1){
    x=time_array[k];
    y=filtered_signal[k];
    fprintf(fp3,"%lf\t %lf\n",x,y);
  }
}
