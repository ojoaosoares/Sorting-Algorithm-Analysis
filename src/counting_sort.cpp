#include "counting_sort.hpp"
#include "maxmin.hpp"

void counting_sort(long long *array, long long n)
{

    long long max, min;
    maxMin(array, n, max, min);

    long long *count = new long long[max - min + 1];

    long long i, j = 0;

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
