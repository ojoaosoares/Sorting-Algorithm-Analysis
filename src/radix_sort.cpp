#include "radix_sort.hpp"
#include <cstdint>

template <typename T>
void radix_sort(T *array, long long l, long long r, long long w)
{
    if (w >= 0)
    {
        long long i = l, j = r;
        
        while (i < j)
        {
            while (((array[i] >> w) & 1) && (i < j)) i++;
            while (!(array[j] >> w) & 1 && (i < j)) j--;

            if (i < j)
            {
                T  aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                
                i++; j--;
            }
        }

        if (((array[r] >> w) & 1) || ((array[j] >> w) & 1)) j++;

        if (l < j) radix_partition(array, l, j - 1, w - 1);
        if (j < r) radix_partition(array, j, r, w - 1);
    }
}


template <typename T>
void radix_partition(T *array, long long l, long long r, long long w) {
    
    if (w >= 0)
    {
        long long i = l, j = r;
        
        while (i < j)
        {
            while (!((array[i] >> w) & 1) && (i < j)) i++;
            while ((array[j] >> w) & 1 && (i < j)) j--;

            if (i < j)
            {
                array[i] = array[j] ^array[i];
                array[j] = array[j] ^array[i];
                array[i] = array[j] ^array[i];
                
                i++; j--;
            }
        }

        if (!((array[r] >> w) & 1) || !((array[j] >> w) & 1)) j++;

        if (l < j) radix_partition(array, l, j - 1, w - 1);
        if (j < r) radix_partition(array, j, r, w - 1);
    }
}


template void radix_sort<long long>(long long *array, long long l, long long r, long long w);
template void radix_sort<int>(int *array, long long l, long long r, long long w);


template void radix_sort<int64_t>(int64_t *array, long long l, long long r, long long w);
template void radix_sort<uint32_t>(uint32_t *array, long long l, long long r, long long w);
template void radix_sort<uint64_t>(uint64_t *array, long long l, long long r, long long w);


template void radix_partition<long long>(long long *array, long long l, long long r, long long w);
template void radix_partition<int>(int *array, long long l, long long r, long long w);


template void radix_partition<int64_t>(int64_t *array, long long l, long long r, long long w);
template void radix_partition<uint32_t>(uint32_t *array, long long l, long long r, long long w);
template void radix_partition<uint64_t>(uint64_t *array, long long l, long long r, long long w);