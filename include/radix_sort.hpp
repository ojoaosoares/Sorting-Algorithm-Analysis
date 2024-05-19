#ifndef RADIX_SORT
#define RADIX_SORT

#include <iostream>

template <typename T>
void radix_sort(T *array, long long l, long long r, long long w = (sizeof(T) * 8) - 1);

template <typename T>
void radix_partition(T *array, long long l, long long r, long long w);

#endif