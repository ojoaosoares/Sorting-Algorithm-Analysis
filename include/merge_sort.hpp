#ifndef MERGE_SORT
#define MERGE_SORT


template <typename T> void intercala(T *resultado, T *copy_left, T *copy_right, long long size_left, long long size_right);

template <typename T> void merge_sort_recursivo(T *array, long long size);

template <typename T> void merge_sort_recursivo_copia(T *array, T *copy, long long size);

template <typename T> void merge_sort(T *array, long long size);

#endif