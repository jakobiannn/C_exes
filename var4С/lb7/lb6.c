#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <string.h>
#include <fcntl.h>
#define BYTECOUNT 20
//FileName1, FileName2, size N
int main(int argc, char const *argv[]) {
	char *buffer;
	int firstF, secondF, numread, count;
	if (argc < 4 || argc > 4) {
	    printf("Wrong arguments.\n");
	    return 0;
	}
	if ((firstF = open(argv[1], O_RDWR))== -1) {
	  perror("open failed on file");
	  exit(1);
	} else {
	  printf("File %s is opened\n", argv[1]);
	}
	buffer = malloc(BYTECOUNT+1);

	for (count = 0; count < BYTECOUNT; count++)
	   buffer[count]='\0';

	read(firstF, buffer, BYTECOUNT);



	if ((secondF = open(argv[2], O_WRONLY))== -1) {
	  perror("open failed on file");
	  exit(1);
	} else {
	  printf("File %s is opened\n", argv[2]);
	}

	int num = atoi(argv[3]);
	for(int i = 0; buffer[i] != '\0'; i++){
		int bubble = (int)buffer[i] - 48;
		printf("buffer:%d argv3:%d\n", bubble, num);
	    if (bubble < num) {
			numread = write(secondF, &buffer[i], 1);
			printf("%d\n", numread);
		}
	}
	close(firstF);
	close(secondF);
    return 0;
}
