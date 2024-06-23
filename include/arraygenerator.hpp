#ifndef ARRAY_GENERATOR
#define ARRAY_GENERATOR

#define RANDOM 1
#define UNIQUE 2
struct gen_array_t{
  int num;
  char * gen; 
};

extern gen_array_t genvet[];

int gen2num(char * gen);

char * num2gen(int num);

template <typename T>
void initVector1(T * vet, long long size);

template <typename T>
void initVector2(T * vet, long long size);

template <typename T>
void initVector3(T * vet, long long size);

template <typename T>
void initVector4(T * vet, long long size);

template <typename T>
void copyVetor(T *v, T *copia, long long n);

#endif