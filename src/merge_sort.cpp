#include "merge_sort.hpp"

/* O Merge Sort é um algoritmo de ordenação eficiente que segue o princípio "dividir para conquistar".
Ele divide a lista não ordenada em partes menores, ordena cada parte e depois mescla essas partes em uma única lista ordenada.
Com complexidade de tempo previsível de O(n log n), o Merge Sort é uma escolha popular para ordenar grandes conjuntos de dados,
apesar de exigir espaço extra na memória para a fase de mesclagem. */


// Recursivo
template <typename T>
void intercala(T *resultado, T *copy_left, T *copy_right, long long size_left, long long size_right) {
    long long i, j, k;
    i = j = k = 0;

    while (i < size_left || j < size_right) {

        if((copy_left[i] < copy_right[j] && i < size_left) || j >= size_right) resultado[k++] = copy_left[i++];
        else if(j < size_right) resultado[k++] = copy_right[j++];
    }

    delete [] copy_left;
    delete [] copy_right;
}

template <typename T>
void merge_sort_recursivo_copia(T *array, T *copy, long long size) {

    if (size == 1) {
        copy[0] = array[0];
        return;
    } 

    T *copy_left = new T[size/2];
    merge_sort_recursivo_copia(array, copy_left, size/2);

    T *copy_right =  new T[size - (size/2)];
    merge_sort_recursivo_copia(&(array[size/2]), copy_right, size - size/2);

    intercala(copy, copy_left, copy_right, size/2, size - size/2);
    
}


template <typename T>
void merge_sort_recursivo(T *array, long long size) {

    T* copy = new T[size];
    
    merge_sort_recursivo_copia(array, copy, size);

    for (long long i = 0; i < size; i++)
        array[i] = copy[i];
}


template void intercala(int *resultado, int *copy_left, int *copy_right, long long size_left, long long size_right);
template void intercala(long long *resultado, long long *copy_left, long long *copy_right, long long size_left, long long size_right);
template void intercala(double *resultado, double *copy_left, double *copy_right, long long size_left, long long size_right);

template void merge_sort_recursivo(int *array, long long size);
template void merge_sort_recursivo(long long *array, long long size);
template void merge_sort_recursivo(double *array, long long size);

template void merge_sort_recursivo_copia(int *array, int *copy, long long size);
template void merge_sort_recursivo_copia(long long *array, long long *copy, long long size);
template void merge_sort_recursivo_copia(double *array, double *copy, long long size);