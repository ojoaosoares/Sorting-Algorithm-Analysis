#include "quick_sort.hpp"
#include "insertion_sort.hpp"

template<typename T> T medianThree(T a, T b, T c) {
    if ((a > b) ^ (a > c)) 
        return a;
    else if ((b < a) ^ (b < c)) 
        return b;
    else
        return c;
}

template<typename T> void particao(T *array, long long left, long long right, long long *i, long long *j)
{
    (*i) = left; (*j) = right;
    
    T median = medianThree(array[left], array[right], array[(left + right) >> 1]);

    do
    {
        while (array[*i] < median) (*i)++;
        while (array[*j] > median) (*j)--;

        if (*i <= *j)
        {
            T aux = array[*i];
            array[*i] = array[*j];
            array[*j] = aux;
            
            (*i)++; (*j)--;
        }

    } while (*i <= *j);   
}

template<typename T> void quick_sort_recursivo(T *array, long long left, long long right)
{
    long long i, j;

    particao(array, left, right, &i, &j);

    if (left < j) 
    {   
        if (j - left <= 50) insertion_sort(array, left, j);
        else  quick_sort_recursivo(array, left, j);
    }
    if (i < right)
    {
        if (right - i <= 50) insertion_sort(array, i, right);
        else quick_sort_recursivo(array, i, right);
    }

    // Análise
    // Quick é um método de ordenação NÃO ESTÁVEL
    // A complexidade no pior caso é O(n²), enquanto no melhor caso é O(n log n)
    // A complexidade de movimentações é O(n log n) em média
    // Adaptável


    // Desvantagens
    // Não estável
    // O pior caso de O(n²) de comparações, que pode ser evitado com melhorias,
    // Como mediana de 3, implementação interativa, e o uso de metodos de ordenação simples

}

template int medianThree<int>(int a, int b, int c);
template long long medianThree<long long>(long long a, long long b, long long c);
template double medianThree<double>(double a, double b, double c);


template void particao<long long>(long long *array, long long left, long long right, long long *i, long long *j);
template void particao<int>(int *array, long long left, long long right, long long *i, long long *j);
template void particao<double>(double *array, long long left, long long right, long long *i, long long *j);

template void quick_sort_recursivo<long long>(long long *array, long long left, long long right);
template void quick_sort_recursivo<double>(double *array, long long left, long long right);
template void quick_sort_recursivo<int>(int *array, long long left, long long right);
