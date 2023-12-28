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

    free(cypher);
}
