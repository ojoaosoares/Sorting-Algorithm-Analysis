#include "bubble_sort.hpp"
#include <cstdint>

template<typename T> void bubble_sort(T *array, long long n)
{
    long long i, j;
    int dont_changed;

    for (i = 0; i < n - 1; i++)
    {
        dont_changed = 1;
        for (j = 1; j < n - i; j++)
        {
            if (array[j] < array[j-1])
            {
                T aux = array[j];
                array[j] = array[j-1];
                array[j - 1] = aux;

                dont_changed = 0;
            }
        }

        if (dont_changed) break;
    }

    // Análise
    // Adaptável
    // Buble sort é um método de ordenação ESTÁVEL
    // A complexidade de comparações é O(n²)
    // A complexidade de movimentações no melhor caso seria O(1), enquanto no pior caso O(n²), 


    // Desvantagens
    // NÃO é estável
        
}

template void bubble_sort<int>(int *array, long long n);
template void bubble_sort<long long>(long long *array, long long n);
template void bubble_sort<double>(double *array, long long n);

template void bubble_sort<int64_t>(int64_t *array, long long n);
template void bubble_sort<uint32_t>(uint32_t *array, long long n);
template void bubble_sort<uint64_t>(uint64_t *array, long long n);
