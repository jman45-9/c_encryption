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
void encryptTarget(char *targetName, char *cypherName, char *outputName)
{
    int *cypher;
    if (cypherName == NULL)
        cypher = generateCypher();
    /*
     * else
     * add code to read cypherName here
    */

    FILE *targetFile = fopen(targetName, "r");
    if (targetFile == NULL)
    {
        fprintf(stderr, "FATAL. NO TARGET FILE FOUND. USR-ERR-001.\n");
        free(cypher);
        exit(1);
    }
    FILE *outputFile = fopen(outputName, "wbx");
    if (outputFile == NULL)
    {
        fprintf(stderr, "FATAL. FAILED TO CREATE OUTPUT FILE, CHECK IF FILE ALREADY EXISTS. USR-ERR-002.\n");
        free(cypher);
        fclose(targetFile);
        exit(1);
    }

    while(1)
    {
        int charValue = fgetc(targetFile);
        if (charValue == EOF)
            break;
        int cypherOutput = *(cypher + charValue);
        fwrite(&cypherOutput, sizeof(cypherOutput), 1, outputFile);
    }

    fclose(targetFile);
    fclose(outputFile);
    free(cypher);
}

int *generateCypher()
{
    CSPRNG rng = csprng_create(rng); //ignore warning on this line :)
    if(!rng)
    {
        fprintf(stderr, "FATAL. NO CSPRNG FOUND. INTERNAL-ERR-000.\n");
        exit(1);
    }

    int *cypherValues = malloc(127*sizeof(int));
    // init cypherValues with -1 in all indexi
    for (int iii = 0; iii < 127; iii++)
        *(cypherValues + iii) = -1;

    FILE *cypherFile = fopen("RENAME_cypherFile.bin", "wb");

    for (int iii = 0; iii < 127; iii++)
    {
        int newValue = abs((int)csprng_get_int(rng) % 65534);
        if (!existsInArray(cypherValues, 127, newValue))
        {
            *(cypherValues + iii) = newValue;
            fwrite(&newValue, sizeof(newValue), 1, cypherFile);
        }
        else
        {
            iii--;
            continue;
        }
    }
    fclose(cypherFile);
    return cypherValues;
}

int existsInArray(int *array, int arrayLength, int value)
{
    for (int iii = 0; iii < arrayLength; iii++)
    {
        if (*(array+iii) == value)
            return 1;
    }
    return 0;
}
  
