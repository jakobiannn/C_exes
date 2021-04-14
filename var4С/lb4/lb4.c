#include <stdio.h>
#include <string.h>


int main() {
	char unix[4] = "UNIX";
	char text[80];

	printf("Type your text there: ");
	gets(text);

	int is_continue = 0;
	char space = ' ';
	char current_test[100];
	int in_unix = 0;

	for(int i; text[i] != '\0'; i++){
		if (text[i] != space){
			is_continue = 1;
		}
		if (is_continue && strchr(unix, text[i]) != NULL){
			strncat(current_test, strchr(unix, text[i]), 1);
		}
		if ((text[i] == space) && (is_continue == 1)){
			if (strchr(current_test, 'U') != NULL
				&& strchr(current_test, 'N') != NULL
				&& strchr(current_test, 'I') != NULL
				&& strchr(current_test, 'X') != NULL) {
					in_unix++;
				}
			is_continue = 0;
		}


	}

	printf("Count of unix word is %d", in_unix);
	return 0;
}
