#ifndef C_ENCRYPTION_MAINH
#define C_ENCRYPTION_MAINH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct args ARGS;

struct args 
{
    char *targetFile;
    char *keyFile;
};

ARGS *parseArgs(int argc, char **argv);

#endif //C_ENCRYPTION_MAINH
