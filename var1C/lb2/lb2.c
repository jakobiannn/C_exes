#include <stdio.h>
#include <limits.h>

void main (){
	int number;
	printf("%s\n", "Введите число");
	scanf("%i", &number);
	if(number & 1){
		printf("%s\n", "true");
	} else {
		printf("%s\n","false");
	}
}
