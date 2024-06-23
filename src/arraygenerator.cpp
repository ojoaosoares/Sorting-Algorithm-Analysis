#include "arraygenerator.hpp"
#include <stdlib.h>
#include <cstdint>
#include <algorithm>

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
void initVector3(T * vet, long long size) {
// Descricao: inicializa vet com valores aleatorios entre 0 e size
// Entrada: vet
// Saida: vet

  // inicializa a parte alocada da vetor com valores aleatorios, porem unicos
  T item = 0;
  for (size_t i = 0; i < size; i++) {
    vet[i] = item++;
  }

  std::random_shuffle(vet, vet + size);
}

template <typename T>
void initVector4(T * vet, long long size) {
// Descricao: inicializa vet com valores aleatorios entre -size e size
// Entrada: vet
// Saida: vet
  
  // inicializa a parte alocada da vetor com valores aleatorios, porem unicos
  T item = (T)(drand48()*size) - size;
  for (size_t i = 0; i < size; i++) {
    vet[i] = item++;
  }

  std::random_shuffle(vet, vet + size);
}

template <typename T>
void copyVetor(T *v, T *copia, long long n)
{
  for (long long i = 0; i < n; i++)
    copia[i] = v[i];
  
}

template void copyVetor<long long>(long long *v, long long *copia, long long n);
template void copyVetor<double>(double*v, double *copia, long long n);
template void copyVetor<int64_t>(int64_t *v, int64_t *copia, long long n);
template void copyVetor<uint32_t>(uint32_t *v, uint32_t *copia, long long n);
template void copyVetor<uint64_t>(uint64_t *v, uint64_t *copia, long long n);

template void initVector1<long long>(long long * vet, long long size);
template void initVector1<double>(double * vet, long long size);
template void initVector1<int64_t>(int64_t * vet, long long size);
template void initVector1<uint32_t>(uint32_t * vet, long long size);
template void initVector1<uint64_t>(uint64_t * vet, long long size);

template void initVector2<long long>(long long * vet, long long size);
template void initVector2<double>(double * vet, long long size);
template void initVector2<int64_t>(int64_t * vet, long long size);
template void initVector2<uint32_t>(uint32_t * vet, long long size);
template void initVector2<uint64_t>(uint64_t * vet, long long size);


template void initVector3<long long>(long long * vet, long long size);
template void initVector3<double>(double * vet, long long size);
template void initVector3<int64_t>(int64_t * vet, long long size);
template void initVector3<uint32_t>(uint32_t * vet, long long size);
template void initVector3<uint64_t>(uint64_t * vet, long long size);


template void initVector4<long long>(long long * vet, long long size);
template void initVector4<double>(double * vet, long long size);
template void initVector4<int64_t>(int64_t * vet, long long size);
template void initVector4<uint32_t>(uint32_t * vet, long long size);
template void initVector4<uint64_t>(uint64_t * vet, long long size);