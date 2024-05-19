#ifndef INSERTION_SORT
#define INSERTION_SORT

#define troca(A,B) {T C = A; A = B; B = C;}

template<typename T> void insertion_sort(T array[], long long l, long long r);

#endif