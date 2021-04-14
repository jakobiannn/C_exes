#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	if(argc == 2){
		if(!strcmp(argv[1], "--help")){
	        printf("Write the names of the files and string you want to count.");
	        return 0;
	    }
	}
    FILE *file;
    char name[10];
	char str[80];

    printf("Write filename: ");
    scanf("%s", &name);

    if ((file = fopen(name, "r")) == NULL) {
        printf("Can't open file\n");
		printf("Press Enter");
        return 0;
    } else {
        printf("File %s opened succesfully\n", name);
    }

	printf("Write string, which you want to count:  ");
    scanf("%s", &str);

    str[sizeof(str) - 1] = '\n';

	char filestring[80];
    int count = 0;

    while (!feof(file)) {
        fscanf(file,"%s", filestring);
		if (strcmp(filestring, str) == 0){
            count++;
        }
	}

	printf("Count of choosen strings: %d.", count);
    fclose(file);

	return 0;
}
