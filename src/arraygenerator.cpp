#include "arraygenerator.hpp"
#include <stdlib.h>

template <typename T>
void initVector1(T * vet, long long size) {
// Descricao: inicializa vet com valores aleatorios entre 0 e size
// Entrada: vet
// Saida: vet
  // inicializa a parte alocada da vetor com valores aleatorios
  for (size_t i=0; i < size; i++){
    vet[i] = (T)(drand48()*size);
  }
}

template <typename T>
void initVector2(T * vet, long long size) {
// Descricao: inicializa vet com valores aleatorios entre -size e size
// Entrada: vet
// Saida: vet
  
  // inicializa a parte alocada da vetor com valores aleatorios
  for (size_t i=0; i < size; i++){
    vet[i] = (T)(drand48()*2*size) - size;
  }
}

template <typename T>
void copyVetor(T *v, T *copia, long long n)
{
  for (long long i = 0; i < n; i++)
    copia[i] = v[i];
  
}

template void copyVetor<long long>(long long *v, long long *copia, long long n);
template void copyVetor<double>(double*v, double *copia, long long n);

template void initVector1<long long>(long long * vet, long long size);
template void initVector1<double>(double * vet, long long size);

template void initVector2<long long>(long long * vet, long long size);
template void initVector2<double>(double * vet, long long size);