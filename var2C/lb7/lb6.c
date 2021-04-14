#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <string.h>
#include <fcntl.h>
#define BYTECOUNT 80
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
	if ((fd = open(argv[1], O_RDWR)) == -1) {
	  perror("open failed on file");
	  exit(1);
	}
	buffer = malloc(BYTECOUNT+1);

	for (count = 0; count < BYTECOUNT; count++)
	   buffer[count]='\0';

	numread = read(fd, buffer, BYTECOUNT);
	close(fd);

	printf("/n Число считанных литер %d\n",numread);
	printf("%s\n", buffer);


    int i = 0;

	while (buffer[i] != *argv[2] && i < BYTECOUNT) i++;
	printf("i: %d\n", i);
	// is it realy works?
	char n = *argv[3] - '0';
	printf("n: %d\n", n);

    for (int j = 0; j < n; j++) {
		remove_element(buffer, i, BYTECOUNT + 1);
    }

	if ((fd = open(argv[1],  O_TRUNC)) == -1) {
	  perror("open failed on file");
	  exit(1);
  	}
	close(fd);


	if ((fd = open(argv[1],  O_WRONLY)) == -1) {
	  perror("open failed on file");
	  exit(1);
  	}
	write(fd, buffer, BYTECOUNT);
	printf("%s\n", buffer);
	close(fd);
	free(buffer);
	return 0;
}
