#ifndef ARRAY_TYPE
#define ARRAY_TYPE


#define INT64 1
#define UINT32 2
#define UINT64 3
#define LONG_LONG 4
struct type_t{
  int num;
  char * type; 
};

extern type_t typevet[];

int type2num(char * type);

#endif