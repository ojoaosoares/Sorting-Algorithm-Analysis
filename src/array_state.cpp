#include "array_state.hpp"
#include <string.h>

state_t statevet[]={
  {RANDOM_STATE, "rand"},
  {ORDERED_STATE, "ord"},
  {REVERSE_ORDERED_STATE, "rev"},
  {ALL_STATE, "all"},
  {0,0}
};

int state2num(char * state)
{
  int i=0;
  while (statevet[i].num) {
    if (!strcmp(statevet[i].state, state)) return statevet[i].num;
    i++;
  }
  
  return 0;
}

char * num2state(int num)
{
  int i=0;
  while (statevet[i].num){
    if (statevet[i].num==num) return statevet[i].state;
    i++;
  }
  return 0;
}
