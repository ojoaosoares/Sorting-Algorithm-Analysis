#include "insertion_sort.hpp"
#include <cstdint>

template<typename T> void insertion_sort(T array[], long long l, long long r)
{
    long long i, j, aux;
    for (i = l + 1; i <= r; i++)
    {
        
        j = i - 1;
        aux = array[i];

        while (j >= l && aux < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = aux;
    }

    // Análise
    // INSERTION sort é um método de ordenação ESTÁVEL
    // A complexidade de comparações é O(n²) no pior caso, e O(n) no melhor caso
    // A complexidade de movimentações é O(n²) no pior caso, e O(n) no melhor caso 
    // Adaptável

    // Desvantagens
    // Muitas operações de movimentação
}

template void insertion_sort<int>(int array[], long long l, long long r);
template void insertion_sort<long long>(long long array[], long long l, long long r);
template void insertion_sort<double>(double array[], long long l, long long r);

template void insertion_sort<int64_t>(int64_t array[], long long l, long long r);
template void insertion_sort<uint32_t>(uint32_t array[], long long l, long long r);
template void insertion_sort<uint64_t>(uint64_t array[], long long l, long long r);
