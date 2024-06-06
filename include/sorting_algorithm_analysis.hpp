#ifndef SORTING_ALGORITHM_ANALYSIS
#define SORTING_ALGORITHM_ANALYSIS

#define ALGINSERTION 1
#define ALGSELECTION 2
#define ALGQSORT3INS 3
#define ALGSHELLSORT 4
#define ALGRECSEL    5
#define ALGBUBLE     6
#define ALGBUCKET    7
#define ALGCOUNTING  8
#define ALGMERGE     9
#define ALGREMERGE  10
#define ALGRADIX    11
#define ALL 12

struct alg_t{
  int num;
  char * name; 
};

extern alg_t algvet[];

int name2num(char * name);

char * num2name(int num);



#endif