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
#include <algorithm>
#include "opt.hpp"
#include "arraygenerator.hpp"

#define _XOPEN_SOURCE
#define _POSIX_C_SOURCE 199309L

void tutorial()
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
  fprintf(stderr,"\t    std\tsort std\n");
  fprintf(stderr,"\t    all\tall\n");
  fprintf(stderr,"\t-t <ll|double>\t(array type)\n");  
  fprintf(stderr,"\t    ll\tlong long\n");
  fprintf(stderr,"\t    double\tdouble\n");
  
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

template <typename T>
void execute(opt_t opt, T* vet, T* copia)
{
  struct timespec inittp, endtp, restp; // Variaves temporais, inicio, fim e diferença

  char pref[100]; // Sera usado para armazenar os resultados

  int retp;

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

    // case ALGCOUNTING:

    //   copyVetor(vet, copia, opt.size);

    //   retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

    //   // counting_sort(copia, opt.size);

    //   retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

    //   clkDiff(inittp, endtp, &restp);

    //   sprintf(pref,"alg counting seed %d size %d time %ld.%.9ld",
    //   opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

    //   std::cout << pref << '\n';

    //   if (opt.alg != ALL) break;

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

    // case ALGRADIX:

    //   copyVetor(vet, copia, opt.size);

    //   retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

    //   radix_sort(copia, 0, opt.size - 1);

    //   retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

    //   clkDiff(inittp, endtp, &restp);

    //   sprintf(pref,"alg radix seed %d size %d time %ld.%.9ld",
    //   opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

    //   std::cout << pref << '\n';   
    //   if (opt.alg != ALL) break;

        if (opt.alg != ALL) break;

        case SORT_STD:

          copyVetor(vet, copia, opt.size);

          retp = clock_gettime(CLOCK_MONOTONIC, &inittp);

          std::sort(vet, vet + opt.size);

          retp = clock_gettime(CLOCK_MONOTONIC, &endtp);

          clkDiff(inittp, endtp, &restp);

          sprintf(pref,"alg sort std %d size %d time %ld.%.9ld",
          opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

          std::cout << pref << '\n';   
          if (opt.alg != ALL) break;

      

      default :
      
        break;
  }
}


template void execute<long long>(opt_t opt, long long *vet, long long *copia);
template void execute<double>(opt_t opt, double *vet, double *copia);

int main (int argc, char ** argv){
    
  // parse_args
  opt_t opt;
  parse_args(argc,argv,&opt);

  
  srand48(opt.seed);

  switch (opt.type)
  {
    case LONG_LONG:
    {
      long long *vet = new long long[opt.size], 
      *copia = new long long[opt.size];

      initVector1(vet, opt.size);

      execute(opt, vet, copia);

      delete[] vet;
      delete[] copia;
      break;
    }

    case DOUBLE:
    {
      double *vet = new double[opt.size], 
      *copia = new double[opt.size];

      initVector1(vet, opt.size);

      execute(opt, vet, copia);

      delete[] vet;
      delete[] copia;
      break;
    }
    default:
      break;
  }
  
  exit(0);
}