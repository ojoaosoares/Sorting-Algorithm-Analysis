#include <stdio.h>
#include <algorithm>
#include <cstdint>
#include "bubble_sort.hpp"
#include "bucket_sort.hpp"
#include "counting_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "radix_sort.hpp"
#include "selection_sort.hpp"
#include "shell_sort.hpp"
#include "arraygenerator.hpp"
#include "stopwatch.hpp"
#include "array_type.hpp"
#include "array_state.hpp"
#include "sorting_algorithm.hpp"
#include "opt.hpp"

template <typename T>
void execute_alg(opt_t opt, T* vet, T* copia)
{
  struct timespec inittp, endtp, restp; // Variaves temporais, inicio, fim e diferença

  char pref[100]; // Sera usado para armazenar os resultados

  switch (opt.alg) {

    case ALL:

    case ALGINSERTION:

      copyVetor(vet, copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &inittp))
        exit(0);

      insertion_sort(copia, 0, opt.size - 1);

      if(clock_gettime(CLOCK_MONOTONIC, &endtp))
        exit(0);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"\t\talg insertion seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGSELECTION:

      copyVetor(vet, copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &inittp))
        exit(0);

      selection_sort(copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &endtp))
        exit(0);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"\t\talg selection seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';
      if (opt.alg != ALL) break;

    case ALGQSORT3INS:

      copyVetor(vet, copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &inittp))
        exit(0);

      quick_sort_recursivo(copia, 0, opt.size - 1);

      if(clock_gettime(CLOCK_MONOTONIC, &endtp))
        exit(0);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"\t\talg quick median 3 + insertion seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGSHELLSORT:
      
      copyVetor(vet, copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &inittp))
        exit(0);

      shell_sort(copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &endtp))
        exit(0);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"\t\talg shell seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGBUBLE:

      copyVetor(vet, copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &inittp))
        exit(0);

      bubble_sort(copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &endtp))
        exit(0);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"\t\talg bubble seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGBUCKET:

      copyVetor(vet, copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &inittp))
        exit(0);

      bucket_sort(copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &endtp))
        exit(0);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"\t\talg bucket seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGCOUNTING:

      copyVetor(vet, copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &inittp))
          exit(0);

      counting_sort(copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &endtp))
        exit(0);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"\t\talg counting seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

    case ALGREMERGE:

      copyVetor(vet, copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &inittp))
        exit(0);

      merge_sort_recursivo(copia, opt.size);

      if(clock_gettime(CLOCK_MONOTONIC, &endtp))
        exit(0);

      clkDiff(inittp, endtp, &restp);

      sprintf(pref,"\t\talg recursive merge seed %d size %d time %ld.%.9ld",
      opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

      std::cout << pref << '\n';

      if (opt.alg != ALL) break;

      case ALGRADIX:

        copyVetor(vet, copia, opt.size);

        if(clock_gettime(CLOCK_MONOTONIC, &inittp))
            exit(0);

        radix_sort(copia, 0, opt.size - 1);

        if(clock_gettime(CLOCK_MONOTONIC, &endtp))
          exit(0);

        clkDiff(inittp, endtp, &restp);

        sprintf(pref,"\t\talg radix seed %d size %d time %ld.%.9ld",
        opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

        std::cout << pref << '\n';   
        if (opt.alg != ALL) break;


      case SORT_STD:

        copyVetor(vet, copia, opt.size);

        if(clock_gettime(CLOCK_MONOTONIC, &inittp))
          exit(0);

        std::sort(vet, vet + opt.size);

        if(clock_gettime(CLOCK_MONOTONIC, &endtp))
          exit(0);

        clkDiff(inittp, endtp, &restp);

        sprintf(pref,"\t\talg sort std %d size %d time %ld.%.9ld",
        opt.seed,opt.size,restp.tv_sec,restp.tv_nsec);

        std::cout << pref << '\n';   

        if (opt.alg != ALL) break;

      default :
        break;
  }
}

template <typename T>
void execute_inital_state(opt_t opt, T* vet, T* copia) {
  
  switch (opt.initial_state)
  {
    case ALL_STATE:

    case RANDOM_STATE:

      std::cout << "\tarray inital state " << num2state(RANDOM_STATE) << '\n';

      execute_alg(opt, vet, copia);

      if(opt.initial_state != ALL_STATE) break;
    
    case ORDERED_STATE:

      std::cout << "\tarray inital state " << num2state(ORDERED_STATE) << '\n';

      std::sort(vet, vet + opt.size);

      execute_alg(opt, vet, copia);

      if(opt.initial_state != ALL_STATE) break;

    case REVERSE_ORDERED_STATE:

      std::cout << "\tarray inital state " << num2state(REVERSE_ORDERED_STATE) << '\n';

      std::sort(vet, vet + opt.size);
      std::reverse(vet, vet + opt.size);
      
      execute_alg(opt, vet, copia);

      if(opt.initial_state != ALL_STATE) break;

    default:
      break;
  }
}

int main (int argc, char ** argv){
    
  // parse_args
  opt_t opt;
  parse_args(argc,argv,&opt);

  
  srand48(opt.seed);

  switch (opt.type)
  {
    case ALL_TYPE: 

    case INT64_TYPE:
    {
      std::cout << "data type " << num2type(INT64_TYPE) << " " << sizeof(int64_t) << " bytes" << '\n';

      int64_t *vet = new int64_t[opt.size],

      *copia = new int64_t[opt.size];

      initVector1(vet, opt.size);

      execute_inital_state(opt, vet, copia);

      delete[] vet; delete[] copia;

      std::cout << '\n';
      
      if(opt.type != ALL_TYPE) break;
    }

    case UINT32_TYPE:
    {
      std::cout << "data type " << num2type(UINT32_TYPE) << " " << sizeof(uint32_t) << " bytes" << '\n';

      uint32_t *vet = new uint32_t[opt.size], 
      *copia = new uint32_t[opt.size];

      initVector2(vet, opt.size);

      execute_inital_state(opt, vet, copia);

      delete[] vet; delete[] copia;

      std::cout << '\n';

      if(opt.type != ALL_TYPE) break;
    }

    case UINT64_TYPE:
    {
      std::cout << "data type " << num2type(UINT64_TYPE) << " " << sizeof(uint64_t) << " bytes" << '\n';

      uint64_t *vet = new uint64_t[opt.size], 
      *copia = new uint64_t[opt.size];

      initVector2(vet, opt.size);

      execute_inital_state(opt, vet, copia);

      delete[] vet; delete[] copia;

      std::cout << '\n';

      if(opt.type != ALL_TYPE) break;
    }

    case LONG_LONG_TYPE:
    {
      std::cout << "data type " << num2type(LONG_LONG_TYPE) << " " << sizeof(long long) << " bytes" << '\n';

      long long *vet = new long long[opt.size], 
      *copia = new long long[opt.size];

      initVector2(vet, opt.size);

      execute_inital_state(opt, vet, copia);

      delete[] vet; delete[] copia;

      std::cout << '\n';

      if(opt.type != ALL_TYPE) break;
      
    }

    
    default:
      break;
  }
  
  exit(0);
}


template void execute_alg<int64_t>(opt_t opt, int64_t *vet, int64_t *copia);
template void execute_alg<uint32_t>(opt_t opt, uint32_t *vet, uint32_t *copia);
template void execute_alg<uint64_t>(opt_t opt, uint64_t *vet, uint64_t *copia);
template void execute_alg<long long>(opt_t opt, long long *vet, long long *copia);


template void execute_inital_state<int64_t>(opt_t opt, int64_t *vet,  int64_t *copia);
template void execute_inital_state<uint32_t>(opt_t opt, uint32_t *vet,  uint32_t *copia);
template void execute_inital_state<uint64_t>(opt_t opt, uint64_t *vet,  uint64_t *copia);
template void execute_inital_state<long long>(opt_t opt, long long *vet,  long long *copia);
