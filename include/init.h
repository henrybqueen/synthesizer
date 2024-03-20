#ifndef INIT_H
#define INIT_H

#include <portaudio.h>
#include <stdio.h>


void init(PaError* err);
void cleanup(PaError* err);
void checkError(PaError err);

#endif