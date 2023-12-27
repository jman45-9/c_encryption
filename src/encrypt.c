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
void encryptTarget(char *targetName, char *keyName, char *outputName)
{
    int *cypher;
    if (keyName == NULL)
        cypher = generateKey();
    /*
     * else
     * add code to read keyName here
    */

    FILE *targetFile = fopen(targetName, "r");
    FILE *outputFile = fopen(outputName, "wb");

    fclose(targetFile);
    fclose(outputFile);
    free(cypher);
}

int *generateKey()
{
    CSPRNG rng = csprng_create(rng); //ignore warning on this line :)
    if(!rng)
    {
        fprintf(stderr, "FATAL. NO CSPRNG FOUND! INTERNAL-ERR-000");
        exit(1);
    }

    int *cypherValues = malloc(127*sizeof(int));
    // init cypherValues with -1 in all indexi
    for (int iii = 0; iii < 127; iii++)
        *(cypherValues + iii) = -1;

    for (int iii = 0; iii < 127; iii++)
    {
        int newValue = abs((int)csprng_get_int(rng) % 255);
        if (existsInArray(cypherValues, 127, newValue))
            *(cypherValues + iii) = newValue;
        else
        {
            iii--;
            continue;
        }
    }
    return cypherValues;
}

int existsInArray(int *array, int arrayLength, int value)
{
    for (int iii = 0; iii < arrayLength; iii++)
    {
        if (*(array+iii) == value)
            return 0;
    }
    return 1;
}
  
