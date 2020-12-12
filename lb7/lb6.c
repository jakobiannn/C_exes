#include <sys/syscall.h>
#include <stdio.h>
int myputchar(int ch) {
    if(write(1, &ch, sizeof(char)) == -1){
		return EOF;
	}
    return ch;
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Something goes wrong.\n");
        return 0;
    }

	if (atoi(argv[1]) != 0){
		char c;
		c = atoi(argv[1]);
		if(myputchar(c) == EOF) {
			printf("Error.\n");
			return;
		}
	} else {
		int c;
		c = argv[1][0];
		if(myputchar(c) == EOF) {
			printf("Error.\n");
			return;
		}
	}

    return 0;
}
