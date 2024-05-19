#include "bucket_sort.hpp"
#include "singlylinkedlistordered.hpp"
#include "maxmin.hpp"
#include <math.h>

template <typename T>
void bucket_sort(T *array, long long n)
{
    T max, min;

    maxMin(array, n, max, min);

    long long buckets_number = n;
    T buckets_range = (int) std::ceil((max - min + 1) / (float)  buckets_number);

    SinglyLinkedListOrdered<T> *buckets = new SinglyLinkedListOrdered<T>[buckets_number + 1];

    for (long long i = 0; i < n; i++)
        buckets[(int) std::floor((array[i] - min + 1) / (float) buckets_range)].insert(array[i]);

    int j = 0;
    
    for (long long i = 0; i <= buckets_number; i++)
        if (!buckets[i].Empty())
        {
            buckets[i].copyArray(&array[j], n - j);
            j += buckets[i].getSize();
        }

    delete[] buckets;
}

template void bucket_sort<long long>(long long *array, long long n);
template void bucket_sort<int>(int *array, long long n);
template void bucket_sort<double>(double *array, long long n);