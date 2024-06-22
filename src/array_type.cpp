#include "array_type.hpp"
#include <string.h>

type_t typevet[]={
  {INT64, "int64"},
  {UINT32, "uint32"},
  {UINT64, "uint64"},
  {LONG_LONG,"ll"},
  {0,0}
};

int type2num(char * type) {
  int i=0;
  while (typevet[i].num) {
    if (!strcmp(typevet[i].type,type)) return typevet[i].num;
    i++;
  }
  
  return 0;
}