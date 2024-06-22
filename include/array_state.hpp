#ifndef ARRAY_STATE
#define ARRAY_STATE

#define RANDOM_STATE 1
#define ORDERED_STATE 2
#define REVERSE_ORDERED_STATE 3
#define ALL_STATE 4

struct type_t{
  int num;
  char * state; 
};

extern type_t statevet[];

int state2num(char * type);

char * num2state(int num);

#endif