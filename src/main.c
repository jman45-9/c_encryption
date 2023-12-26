#include "../header/main.h"

int main(int argc, char **argv)
{

    ARGS *args = parseArgs(argc, argv);
    printf("test: %s", args->targetFile);

    return 0;
}

ARGS *parseArgs(int argc, char **argv)
{
    int checkValue;
    ARGS *args = malloc(sizeof(ARGS));
    args->targetFile = NULL;
    args->keyFile = NULL;

    for (checkValue = 1; checkValue < argc; checkValue++)
    {
        if (checkValue + 1 > argc)
            break;
        if (!strcmp(*(argv+checkValue), "--target-file"))
            args->targetFile = *(argv+checkValue+1);

        //later add code to parse a key file too
    }
    return args;
}

