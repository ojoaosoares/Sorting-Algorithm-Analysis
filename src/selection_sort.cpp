#include "selection_sort.hpp"

template<typename T> void selection_sort(T *array, long long n)
{
    
    long long i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
            if (array[j] < array[min])
                min = j;

        T aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }

    // Análise
    // Selection sort é um método de ordenação NÃO ESTÁVEL
    // A complexidade de comparações é O(n²)
    // A complexidade de movimentações é O(n)


    // Desvantagens
    // Não adaptável
    // Muitas operações de movimentação
}

template void selection_sort<int>(int *array, long long n);
template void selection_sort<long long>(long long *array, long long n);
template void selection_sort<double>(double *array, long long n);

