/*
 * Filename: main.c
 * Purpose: main driver for application
 * Author Jeremy Cope
 * copyright: 2023 Jeremy Cope
*/
#include "../header/main.h"

int main(int argc, char **argv)
{
    ARGS *args = parseArgs(argc, argv);
    if(args->doEncrypt)
        encryptTarget(args->targetFile, args->keyFile);
    
    return 0;
}

ARGS *parseArgs(int argc, char **argv)
{
    int checkValue;
    ARGS *args = malloc(sizeof(ARGS));
    args->targetFile = NULL;
    args->keyFile = NULL;
    args->doEncrypt = 1;

    for (checkValue = 1; checkValue < argc; checkValue++)
    {
        if (checkValue + 1 > argc)
            break;
        if (!strcmp(*(argv+checkValue), "--target-file"))
            args->targetFile = *(argv+checkValue+1);

        if (!strcmp(*(argv+checkValue), "--key-file"))
            args->keyFile = *(argv+checkValue+1);

        if (!strcmp(*(argv+checkValue), "--decrypt"))
            args->doEncrypt = 0;

            }
    return args;
}

