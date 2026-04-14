#ifndef MAP_H
# define MAP_H

typedef struct  s_map
{
    char*       line;
    int         mapFd;
    int         mapLineIdx;
    const char* pathNO;
    const char* pathSO;
    const char* pathWE;
    const char* pathEA;
    const char* colorF;
    const char* colorC;

}   t_map;
#endif