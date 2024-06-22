#include "counting_sort.hpp"
#include "maxmin.hpp"
#include <cstdint>

template <typename T>
void counting_sort(T *array, long long n)
{

    T max, min;
    maxMin(array, n, max, min);

    T *count = new T[max - min + 1];

    T i, j = 0;

    for (i = 0; i < max - min + 1; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[array[i] - min]++;

    for (i = 0; i <= max - min; i++)
    {
        while (count[i] > 0)
        {
            array[j] = i + min;
            count[i]--;
            j++;
        }
    }

    delete[] count;

    // Análise
    // Counting é um método de ordenação sem comparações
    // A complexidade no é O(n + max), O(n) para contagem e
    // O(max) para colocar os valores no array original


    // Desvantagens
    // Complexidade espacial O(max), muita memória extra
    // Na maioria dos casos é impossivel saber a escala dos elementos

}

template void counting_sort<long long>(long long *array, long long n);
template void counting_sort<int>(int *array, long long n);

template void counting_sort<int64_t>(int64_t *array, long long n);
template void counting_sort<uint32_t>(uint32_t *array, long long n);
template void counting_sort<uint64_t>(uint64_t *array, long long n);
