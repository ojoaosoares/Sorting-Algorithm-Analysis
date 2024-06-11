#include "arraygenerator.hpp"
#include <stdlib.h>

void initVector1(long long * vet, int size) {
// Descricao: inicializa vet com valores aleatorios entre 0 e size
// Entrada: vet
// Saida: vet
  int i;
  // inicializa a parte alocada da vetor com valores aleatorios
  for (i=0; i<size; i++){
    vet[i] = (int)(drand48()*size);
  }
}


void initVector2(long long * vet, int size) {
// Descricao: inicializa vet com valores aleatorios entre 0 2^31
// Entrada: vet
// Saida: vet
  int i;
  // inicializa a parte alocada da vetor com valores aleatorios
  for (i=0; i<size; i++){
    vet[i] = lrand48();
  }
}


void initVector3(long long * vet, int size) {
// Descricao: inicializa vet com valores aleatorios entre -2^31 a 2^31
// Entrada: vet
// Saida: vet
  int i;
  // inicializa a parte alocada da vetor com valores aleatorios
  for (i=0; i<size; i++){
    vet[i] = mrand48();
  }
}