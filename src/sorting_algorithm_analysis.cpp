#include "sorting_algorithm_analysis.hpp"
#include <string.h>

alg_t algvet[]={
  {ALGINSERTION,"i"},
  {ALGSELECTION,"s"},
  {ALGQSORT3INS,"q3i"},
  {ALGSHELLSORT,"sh"},
  {ALGBUBLE, "bb"},
  {ALGBUCKET, "bk"},
  {ALGCOUNTING, "c"},
  {ALGREMERGE, "m"},
  {ALGRADIX, "rx"},
  {ALL, "all"},
  {0,0}
};

int name2num(char * name){
  int i=0;
  while (algvet[i].num){
    if (!strcmp(algvet[i].name,name)) return algvet[i].num;
    i++;
  }
  return 0;
}

char * num2name(int num){
  int i=0;
  while (algvet[i].num){
    if (algvet[i].num==num) return algvet[i].name;
    i++;
  }
  return 0;
}
