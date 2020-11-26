#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <string.h>
#include <fcntl.h>
#define BYTECOUNT 1000
	//Имя, символ, величина N
void remove_element(char *array, int index, int array_length) {
   int i;
   for(i = index; i < array_length - 1; i++) array[i] = array[i + 1];

}
int	main(int argc, char *argv[]) {
	char *buffer;
	int fd, numread, count;
	if (argc < 4 || argc > 4) {
		printf("Wrong arguments.\n");
		return 0;
	}
	if ((fd = open(argv[1], O_RDWR))== -1) {
	  perror("open failed on file");
	  exit(1);
	}
	buffer = malloc(BYTECOUNT+1);

	for (count = 0; count < BYTECOUNT; count++)
	   buffer[count]='\0';

	numread = read(fd, buffer, BYTECOUNT);

	printf("/n Число считанных литер %d\n",numread);
	printf("%s\n", buffer);
	close(fd);
	char *copy;
	copy = malloc(BYTECOUNT+1);
	for (int i = 0; buffer[i] != '\0'; i++){
		if (buffer[i] == *argv[2]){
			printf("%c\n", buffer[i]);
			for (int j = i; j <= *argv[3]; j++) {
				remove_element(buffer, j, BYTECOUNT + 1);
			}
		}
	}
	if ((fd = open(argv[1], O_RDWR))== -1) {
	  perror("open failed on file");
	  exit(1);
	}
	write(fd, buffer, BYTECOUNT);
	printf("%s\n", buffer);
	close(fd);
	free(buffer);
	return 0;
}
