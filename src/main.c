#include <portaudio.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 256

typedef struct {

    float frequency;
    int phase;
    float volume;

} Voice;

typedef struct {

    Voice* voices;
    size_t numVoices;
    float* sinTable;
    size_t tableSize;
    size_t time;
    size_t period;

} Synth;




int paStreamCallback(const void *input, void *output, unsigned long frameCount,
                     const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData) {
    
    
    /* fetch user pointer */
    Synth* synth = (Synth*)userData;

    /* pointer to sound output buffer */
    float* out = (float*)output;

    float sample; 

    Voice* voice;
    int dPhase;
    for (int i = 0; i < frameCount; i++) {

        sample = 0;

        for (int voiceId = 0; voiceId < synth->numVoices; voiceId++) {

            voice = &(synth->voices[voiceId]);

            if (synth->time % (synth->period / (voiceId + 1)) < 15000) {
                sample += synth->sinTable[voice->phase] * voice->volume;
            }


            
            dPhase = (int)( voice->frequency * synth->tableSize / (float) SAMPLE_RATE );
            voice->phase = (voice->phase + dPhase) % synth->tableSize;
        }


        *out++ = sample;
        *out++ = sample;

        synth->time += 1;
    }



    return paContinue;
}


void main(void) {

    /* create synth and populate it with voices */

    Synth synth;

    synth.time = 0;
    synth.period = 1327920;

    synth.numVoices = 21;
    synth.tableSize = 4096;

    synth.voices = malloc(synth.numVoices * sizeof(Voice));
    synth.sinTable = malloc(synth.tableSize * sizeof(float));

    for (int i = 0; i < synth.tableSize; i++) {
        synth.sinTable[i] = sinf(2.0 * PI * i / synth.tableSize);
    }

    float A2 = 110.0f;
    float equalTemperedRatio = powf(2, 1 / 12.0f);
    int semiToneOffset = 0;

    int dSemiToneOffset[21] = {
        /*
        A, B, C, D, E, F, G, 
        A, B, C, D, E, F, G, 
        A, B, C, D, E, F, G
        */

        2, 1, 2, 2, 1, 2, 2,
        2, 1, 2, 2, 1, 2, 2,
        2, 1, 2, 2, 1, 2, 0 // last entry doesnt matter
    };
    
    for (int i = 0; i < synth.numVoices; i++) {

        synth.voices[i].frequency = A2 * powf(equalTemperedRatio, semiToneOffset);
        synth.voices[i].phase = 0;
        synth.voices[i].volume = 0.1f;

        semiToneOffset += dSemiToneOffset[i];
    }

    /* now synth is populated with 21 voices */

    /* init portaudio */
    PaError err;
    err = Pa_Initialize();
    checkError(err);


    /* create stream */

    PaStreamParameters outputParameters;
    PaStream* stream;

    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = 2;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

         err = Pa_OpenStream(
            &stream,
            NULL, /* no input */
            &outputParameters,
            SAMPLE_RATE,
            FRAMES_PER_BUFFER,
            NULL,      //paCliffOff
            paStreamCallback,
            &synth 
        );

    err = Pa_StartStream(stream);
    checkError(err);



    Pa_Sleep(1000000);



    
    err = Pa_StopStream(stream);
    checkError(err);

    err = Pa_CloseStream(stream);
    checkError(err);

    /* cleanup portaudio */
    err = Pa_Terminate();
    checkError(err);

    free(synth.sinTable);
    free(synth.voices);


    return;



}