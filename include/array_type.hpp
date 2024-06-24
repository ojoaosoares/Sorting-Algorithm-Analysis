#ifndef ARRAY_TYPE
#define ARRAY_TYPE

#define INT64_TYPE 1
#define LONG_LONG_TYPE 2
#define ALL_TYPE 3
struct type_t{
  int num;
  char * type; 
};

extern type_t typevet[];

int type2num(char * type);

char * num2type(int num);

#endif