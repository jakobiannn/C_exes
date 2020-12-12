#include <stdio.h>

void main() {
	int number;
	printf("%s\n", "Write your number here: ");
	scanf("%d", &number);

	printf("%s%d%s\n", "The dividers of ", number, " is: ");

	for (int i = 2; i < number; i++) {
		if (number % i == 0) {
			printf("%d\n", i);
		}
	}
}
