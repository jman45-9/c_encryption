/*
 * Filename: decrypt.c
 * Purpose: functions to decrypt target file
 * Author: Jeremy Cope
 * Coptright: 2023 Jeremy Cope
*/

#include "../header/decrypt.h"

void decryptTarget(char *targetName, char *cypherName, char *outputFile)
{
    int *cypher = malloc(127*sizeof(int));
    FILE *cypherFile = fopen(cypherName, "rb");
    if(!cypherFile)
    {
        fprintf(stderr, "FATAL. NO CYPHER FILE FOUND, MAKE SURE FILE EXISTS. USR-ERR-003.\n");
        exit(1);
    }
    for (int iii = 0; iii < 127; iii++)
        fread((cypher+iii), sizeof(int), 1, cypherFile);
    fclose(cypherFile);

    FILE *targetFile = fopen(targetName, "rb");
    if(!targetFile)
    {
        fprintf(stderr, "FATAL. TARGET NOT FOUND. USR-ERR-005.\n");
        exit(1);
    }
    FILE *output = fopen(outputFile, "w");
    if(!output)
    {
        fprintf(stderr, "FATAL. FAILED TO CREATE OUTPUT. INTERNAL-ERR-002.\n"); 
        exit(1);
    }

    fclose(targetFile);
    fclose(output);
    free(cypher);
}
