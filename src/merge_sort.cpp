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

/* 
    Esta é uma versão interativa do algoritmo de Merge Sort. Ela ordena e mescla pares de tamanho 2^i,
    onde i >= 0 e 2^i é menor que o tamanho total da lista.
    O vetor auxiliar é utilizado para copiar os pares já ordenados e, em seguida, ele é transferido de volta
    para o vetor original ao final de cada loop.
    O loop externo controla a ordenação e mesclagem das partes do array. Ele começa com pares pequenos e gradualmente
    trabalha em direção a pares maiores.
    O loop interno opera sobre cada par de elementos e realiza a ordenação e mesclagem. Ele divide o par em duas partes:
    a primeira parte de esquerda até meio e a segunda de meio até direita. Os índices x e y ajudam a acompanhar a posição
    atual de ambos os lados.
    O processo de mesclagem é feito comparando os elementos nos índices x e y, escolhendo o menor (ou igual) e copiando-o
    para o vetor auxiliar. Isso ocorre até que todos os elementos do par sejam mesclados de volta na ordem correta.
    Após mesclar todos os pares do loop interno, o vetor auxiliar é transferido de volta para o vetor original, efetivamente
    atualizando a parte ordenada.
    Esse processo continua até que todos os elementos estejam totalmente ordenados no vetor original.
    O algoritmo de Merge Sort é eficiente e garante que o vetor esteja ordenado ao final da sua execução.
*/

// Interativo 

template <typename T>
void merge_sort(T *array, long long size) {

    T *copy = new T[size];

    long long l, middle, r, x, y;
    for (long long i = 1; i < size; i*=2) {
        for (long long j = 0; j + i < size; j+= i*2)
        {
            l = j;
            middle = l + i;
            r = l + 2*i;
            if (r > size) r = size;
            
            x = l;
            y  = middle;
            
            while (l < r)
            {
                if((array[x] < array[y] || y >= r) &&  (x < middle)) copy[l++] = array[x++];
                else if((array[y] <= array[x] || x>= middle) && y < r) copy[l++] = array[y++];
            }
            
            for (int k = j; k <  r; k++)
                array[k] = copy[k];
        } 
    }

    delete [] copy;
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

template void merge_sort(int *array, long long size);
template void merge_sort(long long *array, long long size);
template void merge_sort(double *array, long long size);