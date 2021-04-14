#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUFFSIZE 80

int main(int argc, char const *argv[]) {
	if (argc != 4) {
        printf("write your filenames for concatenate.\n");
        return 0;
    }

	char *buffer1 = malloc(BUFFSIZE + 1);
	char *buffer2 = malloc(BUFFSIZE + 1);

	int firstF, secondF, thirdF;

	if ((firstF = open(argv[1], O_RDWR))== -1) {
	  perror("open failed on file");
	  exit(1);
	} else {
	  printf("File %s is opened\n", argv[1]);
	}
	read(firstF, buffer1, BUFFSIZE);
	close(firstF);

	if ((secondF = open(argv[2], O_RDWR))== -1) {
	  perror("open failed on file");
	  exit(1);
	} else {
	  printf("File %s is opened\n", argv[2]);
	}
	read(firstF, buffer2, BUFFSIZE);

	if ((thirdF = open(argv[3], O_RDWR))== -1) {
	  perror("open failed on file");
	  exit(1);
	} else {
	  printf("File %s is opened\n", argv[3]);
	}

	char *buffer3 = strcat(buffer1, buffer2);
	write(thirdF, buffer3, BUFFSIZE);

	close(secondF);
	close(thirdF);
	return 0;
}
