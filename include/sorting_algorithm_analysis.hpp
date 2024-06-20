#ifndef SORTING_ALGORITHM_ANALYSIS
#define SORTING_ALGORITHM_ANALYSIS

#define ALGINSERTION 1
#define ALGSELECTION 2
#define ALGQSORT3INS 3
#define ALGSHELLSORT 4
#define ALGBUBLE     5
#define ALGBUCKET    6
#define ALGCOUNTING  7
#define ALGREMERGE   8
#define ALGRADIX     9
#define ALL          10


#define LONG_LONG 1
#define DOUBLE 2

struct alg_t{
  int num;
  char * name; 
};

struct type_t{
  int num;
  char * type; 
};

extern alg_t algvet[];

int name2num(char * name);

char * num2name(int num);

int type2num(char * type);

#endif