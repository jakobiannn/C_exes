#include <stdio.h>

void main() {
  int number;
  printf("%s\n","Write your number there: ");
  scanf("%d", &number);

  int m, n;
  printf("%s\n", "Write your m limit");
  scanf("%d", &m);

  printf("%s\n", "Write your n limit");
  scanf("%d", &n);

  int mask = 1;
  for (int i = 0; i < (n - m); i++) {
    mask <<= 1;
    mask |= 1;
  }

  mask <<= m - 1;

  printf("%d\n", mask);
  number |= mask;

  printf("%d\n", number);
}
