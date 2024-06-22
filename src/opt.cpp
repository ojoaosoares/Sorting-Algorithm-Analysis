#include "opt.hpp"
#include "array_type.hpp"
#include "sorting_algorithm.hpp"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
     opt->type = 0;


     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "z:s:a:t:h")) != EOF){
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
          case 't':
            opt->type = type2num(optarg);
                  break;
         case 'h':
         default:
                  tutorial();
                  exit(1);

       }
     }
     if (!opt->alg || !opt->type) {
       tutorial();
       exit(1);
     }
}