#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
	if(argc == 2){
		if(!strcmp(argv[1], "--help")){
			printf("Type your file name.\n");
			printf("The program displays the character with the maximum number of occurrences in the text.\n");
			return 0;
		}
	}
	FILE *file;
	char name[10];

	printf("Write the filename: ");
	scanf("%s", &name);
	if ((file = fopen(name, "r")) == NULL) {
		printf("Can't open file");
		getchar();
		return 0;
	} else {
		printf("File %s opened succesfully\n", name);
	}


	char fileInfo[20];
	int symbols[256];
	//Переменная обозначающая наибольшее количество вхождений буквы
	int biggest = 0;
	//Код символа с наибольшим вхождением
	int biggestSymbol = 0;

    while (fgets(fileInfo, sizeof(fileInfo), file)) {
        for(int i=0; fileInfo[i] != '\n'; i++) {
			symbols[fileInfo[i]]++;
			
			if(symbols[fileInfo[i]] > biggest) {
				biggest = symbols[fileInfo[i]];
				biggestSymbol = fileInfo[i];
			}
		}
    }

	fclose(file);
	printf("The largest number of occurrences of the character %c", biggestSymbol);
	return 0;
}
