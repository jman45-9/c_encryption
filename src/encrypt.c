/*
 * Filename: encrypt.c
 * Purpose: fucntions to encrypt target file
 * Author: Jeremy Cope
 * copyright: 2023 Jeremy Cope
*/

#include "../header/encrypt.h"

/*
 * encrypts target file
 * @param targetName - name of file to be encrypted
 * @param keyName - name of file containg encryption key, pass NULL is no file exists
*/
void encryptTarget(char *targetName, char *keyName)
{
    int *cypher = malloc(sizeof(int)*127);

    if (keyName == NULL)
        generateKey();

    free(cypher);
}

void generateKey()
{
    CSPRNG rng = csprng_create(rng); //ignore warning on this line :)
    if(!rng)
    {
        fprintf(stderr, "FATAL. NO CSPRNG FOUND! ERR-001");
        exit(1);
    }

    for (int iii = 0; iii < 127; iii++)
    {
        int cypherValue = abs((int)csprng_get_int(rng) % 255);
        printf("test: %d\n", cypherValue);
    }
}
