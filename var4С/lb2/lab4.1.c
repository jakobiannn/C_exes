#include <stdio.h>

int main() {
  int number, nByte;

  printf("Write the number:\n");
  scanf("%d", &number);

  printf("Write the number of bite, which you want to set:\n");
  scanf("%d", &nByte);

  int byte = 1;

  byte <<= nByte;
  number |= nByte;

  printf("Completed number: %d\n",number);
  return 0;
}
