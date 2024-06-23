#ifndef ARRAY_GENERATOR
#define ARRAY_GENERATOR

#define RANDOM_SIGNED 1
#define RANDOM_UNSIGNED 2
#define UNIQUE_SIGNED 3
#define UNIQUE_UNSIGNED 4
struct domain_array_t{
  int num;
  char * gen; 
};

extern domain_array_t domainvet[];

int domain2num(char * gen);

char * num2domain(int num);

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