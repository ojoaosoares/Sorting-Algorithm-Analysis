#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <time.h>

void clkDiff(struct timespec t1, struct timespec t2, struct timespec * res);

#endif