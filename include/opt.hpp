#ifndef OPTION_HPP
#define OPTION_HPP

// struct opt (opções) 
//é um struct que serve para armazenar as opções na linha de codigo
typedef struct opt{
  int size; // Tamanho do array
  int seed; // Semente de geração dos numeros pseudo-aleatorios, para receber resultados consistentes
  int alg; // Qual algoritimo devera ser usado
  int type; // Tipo de variavel
} opt_t;

void parse_args(int argc, char ** argv, opt_t * opt);

void tutorial();

#endif