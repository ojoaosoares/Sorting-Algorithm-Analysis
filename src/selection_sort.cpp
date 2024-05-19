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


template <typename T>
void recursiveSelectionSort(T *arr, long long  l, long long r)
{
    // find the minimum element in the unsorted subarray `[i…n-1]`
    // and swap it with `arr[i]`
    long long min = l;
    for (long long j = l + 1; j <= r; j++)
    {
        // if `arr[j]` is less, then it is the new minimum
        if (arr[j] < arr[min]) {
            min = j;    // update the index of minimum element
        }
    }

    // swap the minimum element in subarray `arr[i…n-1]` with `arr[i]`
    if (min!=l)
    {
        T aux = arr[l];
        arr[l] = arr[min];
        arr[min] = aux;
    }

    if (l + 1 < r) {
        recursiveSelectionSort(arr, l + 1, r);
    }
}


template void selection_sort<int>(int *array, long long n);
template void selection_sort<long long>(long long *array, long long n);
template void selection_sort<double>(double *array, long long n);

template void recursiveSelectionSort(int *arr, long long  l, long long r);
template void recursiveSelectionSort(long long *arr, long long  l, long long r);
template void recursiveSelectionSort(double *arr, long long  l, long long r);
