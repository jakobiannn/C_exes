#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <string.h>
#include <fcntl.h>
#define BYTECOUNT 20
//FileName1, FileNameN, size N
int main(int argc, char const *argv[]) {
	char *buffer;
	buffer = malloc(BYTECOUNT+1);
	int count;
	for (count = 0; count < BYTECOUNT; count++)
	   buffer[count]='\0';

	int nSize = atoi(argv[argc - 1]);
	int currentF;
	int finalF;

	for (int i = 1; i < argc - 1; i++){
		if ((currentF = open(argv[i], O_RDONLY))== -1) {
		  perror("open failed on file");
		  exit(1);
		} else {
		  printf("File %s is opened\n", argv[i]);
		  read(currentF, buffer, BYTECOUNT);
  		  printf("File info:%s\n", buffer);
		}




		if(strlen(buffer) < nSize) {
			printf("File %s is less then %d\n", argv[i], nSize);

			if ((finalF = open("final.txt", O_RDWR | O_CREAT))== -1) {
			  perror("open failed on file");
			  exit(1);
			} else {
			  printf("File %s is opened\n", argv[i]);
			  write(finalF, buffer, BYTECOUNT);
			}
			close(finalF);

		}
		close(currentF);
		for (count = 0; count < BYTECOUNT; count++)
		   buffer[count]='\0';
	}
    return 0;
}
