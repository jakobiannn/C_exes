#include <stdio.h>
#include <string.h>
int main() {
	//содадим массив латинских букв
	char latin[] = {"ABCDEFGHIJKLMNOPRSTUVWXYZ"};
	char str[100];

	//считаем нужную нам последовательность
	printf("%s\n", "Write your string there: ");
	gets(str);

	//проверим каждый символ на вхождение в массив латинских букв
	//если символ не является латинским, то присваиваем ему значение пробела
	for(int i = 0; i < strlen(str); i++) {
		if (strchr(latin, str[i]) == 0){
			str[i] = ' ';
		}
    }

	char *spacep = " ";
	char space = *spacep;

	//выведем без пробелов получившуюся последовательность
	printf("%s\n", "Sorted string:");
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] != space){
			printf("%c", str[i]);
		}
	}

	return 0;
}
