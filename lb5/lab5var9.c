#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	if(argc == 2){
		if(!strcmp(argv[1], "--help")){
	        printf("Write the names of the files you want to join.\nTheir contents will be written in the file 'copy.txt'.\n");
	        return 0;
	    }
	}
    FILE *first, *second, *conc;
    char name[10];

    printf("Write 1st filename: ");
    scanf("%s", &name);
    if ((first = fopen(name, "r")) == NULL) {
        printf("Can't open file");
        getchar();
        return 0;
    } else {
        printf("File %s opened succesfully\n", name);
    }

    printf("Write 2nd filename: ");
    scanf("%s", &name);
    if ((second = fopen(name, "r")) == NULL)
    {
        printf("Can't open file");
        getchar();
        return 0;
    } else {
        printf("File %s opened succesfully\n", name);
    }
    if ((conc = fopen("conc.txt", "w")) == NULL)
    {
        printf("Can't open file");
        getchar();
        return 0;
    } else {
        printf("File conc.txt opened succesfully\n");
    }
    char fileInfo[20];
    while (fgets(fileInfo, sizeof(fileInfo), first)) {
        fwrite(fileInfo, sizeof(char), strlen(fileInfo), conc);
    }
    fputc('\n', conc);
    while (fgets(fileInfo, sizeof(fileInfo), second)) {
        fwrite(fileInfo, sizeof(char), strlen(fileInfo), conc);
    }

    fclose(first);
    fclose(second);
    fclose(conc);

    return 0;
}
