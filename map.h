#ifndef MAP_H
# define MAP_H

#include <stdbool.h>

typedef struct  s_map
{
    char*       line;
    int         mapFd;
    bool        inMap;
    char* pathNO;
    char* pathSO;
    char* pathWE;
    char* pathEA;
    char* colorF;
    char* colorC;
}   t_map;
#endif