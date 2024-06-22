#ifndef ARRAY_TYPE
#define ARRAY_TYPE

#define LONG_LONG 1
#define DOUBLE 2

struct type_t{
  int num;
  char * type; 
};

extern type_t typevet[];

int type2num(char * type);

#endif