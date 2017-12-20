#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include <stdint.h>


// arduno definitions...
unsigned long millis();
void delay(unsigned long ms);


#include <time.h>
#define analogRead(dummy) ( (int)time(NULL) )
#define randomSeed(x) srandom(x)
#define random(M,N) ( M + rand() / (RAND_MAX / (N - M + 1) + 1) )
#endif
