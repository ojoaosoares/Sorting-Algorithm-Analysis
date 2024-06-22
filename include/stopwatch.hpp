#ifndef STOPWATCH
#define STOPWATCH

#include <time.h>

void clkDiff(struct timespec t1, struct timespec t2, struct timespec * res);

#endif