#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <string.h>
#include <fcntl.h>
	//Копируемый, имя копии, величина блока
int	main(int argc, char *argv[]) {
	char *buffer;
	int firstF, copy, numread;
	if (argc < 4 || argc > 4) {
		printf("Wrong arguments.\n");
		return 0;
	}
	if ((firstF = open(argv[1], O_RDWR)) == -1) {
	  perror("open failed on file");
	  exit(1);
	} else {
	 	printf("File %s opened succesfully.\n", argv[1]);
	}

	int block_size = atoi(argv[3]);
	buffer = malloc(block_size);

	for (int count = 0; count < block_size; count++)
	   buffer[count]='\0';

   	if ((copy = open(argv[2],  O_RDWR)) == -1) {
   	  perror("open failed on file");
   	  exit(1);
  	} else {
	  printf("File %s opened succesfully.\n", argv[2]);
  	}
	int num = 0;
	while (read(firstF, buffer, block_size)) {
		num = write(copy, buffer, block_size);
		printf("%d\n", num);
	}

	close(firstF);
	close(copy);

	free(buffer);
	return 0;
}
