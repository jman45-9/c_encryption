#ifndef C_ENCRYPTION_ENCRYPTH
#define C_ENCRYPTION_ENCRYPTH

#include <stdio.h>
#include <stdlib.h>

#include "../src/duthomhas/csprng.h"

void encryptTarget(char *targetName, char *keyName);
void generateKey();


#endif //C_ENCRYPTION_ENCRYPTH
