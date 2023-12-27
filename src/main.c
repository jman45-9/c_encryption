#include "../header/main.h"

int main(int argc, char **argv)
{

    
    CSPRNG rng = csprng_create( rng ); //ignore warning on this line
    if(!rng)
    {
        fprintf(stderr, "CSPRNG INIT FAILED ERR-000");
        exit(1);
    }

    printf("test: %ld\n", csprng_get_int(rng));


    rng = csprng_destroy(rng);
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

        if (!strcmp(*(argv+checkValue), "--decrypt"))
            args->doEncrypt = 0;

        //later add code to parse a key file too
    }
    return args;
}

