#ifndef C_ENCRYPTION_ENCRYPTH
#define C_ENCRYPTION_ENCRYPTH

#include <stdio.h>
#include <stdlib.h>

#include "../src/duthomhas/csprng.h"

void encryptTarget(char *targetName, char *keyName, char *outputFile);
int *generateKey();

int existsInArray(int *array, int arrayLength, int value);

#endif //C_ENCRYPTION_ENCRYPTH
