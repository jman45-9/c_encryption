#ifndef C_ENCRYPTION_MAINH
#define C_ENCRYPTION_MAINH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encrypt.h"

typedef struct args ARGS;

struct args 
{
    char *targetFile;
    char *cypherFile;
    char *outputFile;
    int doEncrypt;
};

ARGS *parseArgs(int argc, char **argv);

#endif //C_ENCRYPTION_MAINH
