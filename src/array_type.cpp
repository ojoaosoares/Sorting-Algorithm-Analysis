#include "array_type.hpp"
#include <string.h>

type_t typevet[]={
  {LONG_LONG,"ll"},
  {DOUBLE,"double"},
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