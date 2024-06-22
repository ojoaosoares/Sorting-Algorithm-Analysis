#include "array_type.hpp"
#include <string.h>

type_t typevet[]={
  {INT64_TYPE, "int64"},
  {UINT32_TYPE, "uint32"},
  {UINT64_TYPE, "uint64"},
  {LONG_LONG_TYPE,"ll"},
  {ALL_TYPE, "all"},
  {0,0}
};

int type2num(char * type)
{
  int i=0;
  while (typevet[i].num) {
    if (!strcmp(typevet[i].type,type)) return typevet[i].num;
    i++;
  }
  
  return 0;
}

char * num2type(int num)
{
  int i=0;
  while (typevet[i].num){
    if (typevet[i].num==num) return typevet[i].type;
    i++;
  }
  return 0;
}