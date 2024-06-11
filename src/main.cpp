#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "bubble_sort.hpp"
#include "bucket_sort.hpp"
#include "counting_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "radix_sort.hpp"
#include "selection_sort.hpp"
#include "shell_sort.hpp"
#include "sorting_algorithm_analysis.hpp"

#define _XOPEN_SOURCE
#define _POSIX_C_SOURCE 199309L

// struct opt (opções) 
//é um struct que serve para armazenar as opções na linha de codigo
typedef struct opt{
  int size; // Tamanho do array
  int seed; // Semente de geração dos numeros pseudo-aleatorios, para receber resultados consistentes
  int alg; // Qual algoritimo devera ser usado
} opt_t;


void initVector(long long * vet, int size){
// Descricao: inicializa vet com valores aleatorios
// Entrada: vet
// Saida: vet
  int i;
  // inicializa a parte alocada da vetor com valores aleatorios
  for (i=0; i<size; i++){
    vet[i] = (int)(drand48()*size);
  }
}

void copyVetor(long long *v, long long *copia, long long n)
{
  for (long long i = 0; i < n; i++)
    copia[i] = v[i];
  
}

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr,"Instructions\n");
  fprintf(stderr,"\t-z <int>\t(vector size)\n");
  fprintf(stderr,"\t-s <int>\t(initialization seed)\n");
  fprintf(stderr,"\t-a <s|i|q3i|sh|bb|bk|c|m|rx|all>\t(algorithm)\n");
  fprintf(stderr,"\t    s\tselection\n");
  fprintf(stderr,"\t    i\tinsertion\n");
  fprintf(stderr,"\t    q3i\tquicksort+median3+insertion\n");
  fprintf(stderr,"\t    sh\tshell\n");
  fprintf(stderr,"\t    bb\tbubble\n");
  fprintf(stderr,"\t    bk\tbucket\n");
  fprintf(stderr,"\t    c\tcounting\n");
  fprintf(stderr,"\t    m\tmerge\n");
  fprintf(stderr,"\t    rx\tradix\n");
  fprintf(stderr,"\t    all\tall\n");
}

void parse_args(int argc, char ** argv, opt_t * opt)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc, argv, opt
// Saida: opt
{
     // variaveis externas do getopt
     extern char * optarg;
     extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opt->seed = 1;
     opt->size = 10;
     opt->alg = 0;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "z:s:a:h")) != EOF){
       switch(c) {
         case 'z':
	          opt->size = atoi(optarg);
                  break;
         case 's':
	          opt->seed = atoi(optarg);
                  break;
         case 'a':
		        opt->alg = name2num(optarg);
                  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
     }
     if (!opt->alg) {
       uso();
       exit(1);
     }
}

void clkDiff(struct timespec t1, struct timespec t2, struct timespec * res)
// Descricao: calcula a diferenca entre t2 e t1, que e armazenada em res
// Entrada: t1, t2
// Saida: res
{
  if (t2.tv_nsec < t1.tv_nsec){
    // ajuste necessario, utilizando um segundo de tv_sec
    res-> tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
    res-> tv_sec = t2.tv_sec-t1.tv_sec-1;
  } else {
    // nao e necessario ajuste
    res-> tv_nsec = t2.tv_nsec-t1.tv_nsec;
    res-> tv_sec = t2.tv_sec-t1.tv_sec;
  }
}

int main (int argc, char ** argv){

  long long *vet;
  
  char pref[100]; // Sera usado para armazenar os resultados

  struct timespec inittp, endtp, restp; // Variaves temporais, inicio, fim e diferença
  

  // parse_args
  opt_t opt;
  parse_args(argc,argv,&opt);

  vet = new long long[opt.size];

  // Gerar números aleatorios com a seed
  srand48(opt.seed);

  initVector(vet, opt.size);

  long long *copia = new long long[opt.size];

  //if (opt.size < 100) printVector(vet, opt.size);

  int retp;
  
  // execute algorithm
  switch (opt.alg) {
    case ALL:

    case ALGINSERTION:

      copyVetor(vet, copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

      insertion_sort(copia, 0, opt.size - 1);

      retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"alg insertion seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGSELECTION:

      copyVetor(vet, copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

      selection_sort(copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"alg selection seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';
      if (opt.alg != ALL) break;

    case ALGQSORT3INS:

      copyVetor(vet, copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

      quick_sort_recursivo(copia, 0, opt.size - 1);

      retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"alg quick median 3 + insertion seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGSHELLSORT:
      
      copyVetor(vet, copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

      shell_sort(copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"alg shell seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGBUBLE:

      copyVetor(vet, copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

      bubble_sort(copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"alg bubble seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGBUCKET:

      copyVetor(vet, copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

      bucket_sort(copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"alg bucket seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGCOUNTING:

      copyVetor(vet, copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

      counting_sort(copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"alg counting seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGREMERGE:

      copyVetor(vet, copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

      merge_sort_recursivo(copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"alg recursive merge seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGRADIX:

      copyVetor(vet, copia, opt.size);

      retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

      radix_sort(copia, 0, opt.size - 1);

      retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"alg radix seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';   
      if (opt.alg != ALL) break;

      default :
        break;
  }

  delete[] vet;
  delete[] copia;

  exit(0);
}