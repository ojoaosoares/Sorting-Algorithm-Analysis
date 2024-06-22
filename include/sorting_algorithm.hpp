#ifndef SORTING_ALGORITHM
#define SORTING_ALGORITHM

#define ALGINSERTION 1
#define ALGSELECTION 2
#define ALGQSORT3INS 3
#define ALGSHELLSORT 4
#define ALGBUBLE     5
#define ALGBUCKET    6
#define ALGCOUNTING  7
#define ALGREMERGE   8
#define ALGRADIX     9
#define SORT_STD     10
#define ALL          11

struct alg_t{
  int num;
  char * name; 
};

extern alg_t algvet[];

int name2num(char * name);

char * num2name(int num);

#endif