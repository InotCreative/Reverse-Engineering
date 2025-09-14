#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void generar_clave(char *key,int keySize) {
  srand(time(NULL));
  rand();

  FILE *keyFile = fopen("key.txt", "w");

  int iVar1;
  int loopCounter;
  char allAlphaNum [72];
  
  strncpy(allAlphaNum,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", 63);
  for (loopCounter = 0; loopCounter < keySize; loopCounter = loopCounter + 1) {
    iVar1 = rand();
    key[loopCounter] = allAlphaNum[iVar1 % 62];
  }
  key[keySize] = '\0';

  fprintf(keyFile, "%s", key);

  fclose(keyFile);
}

int main() {
    char key[48];
    generar_clave(key, 32);
}