#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char symbol;

    printf("Write your symbol: ");
    scanf("%c", &symbol);
    symbol = toupper(symbol);

    char alphabet[] = "AEIOUYBCDFGHJKLMNPQRSTVWXYZ";

    char *istr = strchr(alphabet, symbol);

    if (istr != NULL) {
        if (istr - alphabet + 1 <= 5) {
            printf("it's vowel\n");
        } else {
            printf("it's consonant letter\n");
        }
    } else {
        printf("This symbol is not a letter");
    }
    return 0;
}
