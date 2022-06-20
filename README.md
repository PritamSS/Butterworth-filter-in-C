# Butterworth-filter-in-C
A low pass butterworth filter was implemented in C where the user can input the amplitude and the output are three text files with the desired sine signal which should be the output, the noisy signal and the filtered signal the true output







## Implementation
The function, ButterworthLowpassFilter0050SixthOrder, is the one which does the filterring of the noisy signal which has the coefficients values set. since it is a sixth order filter six coefficient values are set. The noisy signal is created by adding random values to the sine wave then these values are passed through the finction which filters this signal.
 
## Output
The outputs are the y axis values which are created and stored in the .txt files.
1. The sine2.txt file contains the sine wave
2. The noisy_signal2.txt contains the noisy signal
3. The filtered_signal2.txt contains the filteres signal

These .txt files can be plotted using gnuplot application

1. Noisy signal

![img1](https://drive.google.com/uc?export=view&id=1IrGY04t2Tvn_3BfMmBYUOqPSx-VaygWw)




2. Sine wave/ Expected output

![img2](https://drive.google.com/uc?export=view&id=1CeVA94NF-g2vARN1B4tyF8iwKxbN1YZG)




3. Filtered output

![img3](https://drive.google.com/uc?export=view&id=1wdgMTWnUlew09jhTvqY85BHT5EvGBO5O)

