#include <portaudio.h>
#include <stdio.h>


void init(PaError* err) {
    *err = Pa_Initialize();
}



void cleanup(PaError* err) {
    *err = Pa_Terminate();
}


void checkError(PaError err) {
    if (err != paNoError) {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    }
}