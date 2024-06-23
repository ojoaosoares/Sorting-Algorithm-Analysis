#include "opt.hpp"
#include "array_type.hpp"
#include "array_state.hpp"
#include "sorting_algorithm.hpp"
#include "arraygenerator.hpp"
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

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "z:s:a:d:i:t:h")) != EOF){
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
          case 'd':
            opt->domain = domain2num(optarg);
                  break;
          case 'i':
            opt->initial_state = state2num(optarg);
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
     if (!opt->alg || !opt->type || !opt->initial_state || !opt->domain) {
       tutorial();
       exit(1);
     }
}

void tutorial()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr,"Instructions\n");
  fprintf(stderr,"\t-z <int>\t(vector size)\n");
  fprintf(stderr,"\t-s <int>\t(initialization seed)\n");
  fprintf(stderr,"\t-a <s|i|q3i|sh|bb|bk|c|m|rx|std|all>\t(algorithm)\n");
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
  fprintf(stderr,"\t-i <rand|ord|rev|all>\t(array inital state)\n");  
  fprintf(stderr,"\t    rand\trandom\n");
  fprintf(stderr,"\t    ord\tordered\n");
  fprintf(stderr,"\t    rev\treverse ordered\n");
  fprintf(stderr,"\t    all\tall\n");
  fprintf(stderr,"\t-t <int64|uint32|uint64|ll|all>\t(array type)\n");  
  fprintf(stderr,"\t    int64\tint 64 bits\n");
  fprintf(stderr,"\t    uint32\tunsigened int 32 bits\n");
  fprintf(stderr,"\t    uint64\tunsigened int 64 bits\n");
  fprintf(stderr,"\t    ll\tlong long\n");
  fprintf(stderr,"\t    all\tall\n");
  
  
  
}
