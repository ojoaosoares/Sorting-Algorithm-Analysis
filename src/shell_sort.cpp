#include "shell_sort.hpp"

template<typename T> void shell_sort(T array[], long long n) {

    for (long long h = n/2; h > 0; h /= 2)
    {
        for (long long i = h; i < n; i++)
        {
            long long aux = array[i], j = i - h;

            while (j >= 0 && aux < array[j])
            {
                array[j + h] = array[j];
                j -= h;;
            }

            if (i != j+h)
                array[j+h] = aux;
        }
    }

    // Análise
    // Shell sort é um método de ordenação NÃO ESTÁVEL
    // Adaptável, a complexidade depende da sequência
    // A complexidade de tempo é O(n²)


    // Desvantagens
    // Não estável
    // Muitas operações de movimentação


}


template void shell_sort<int>(int array[], long long n);
template void shell_sort<long long>(long long array[], long long n);
template void shell_sort<double>(double array[], long long n);