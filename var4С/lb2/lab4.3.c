#include <stdio.h>

int main() {
    int number;

    printf("Write your number: ");
    scanf("%d", &number);

    int bubble = 1;
    int count = 1;

    while(number != bubble){
        bubble <<= 1;
        count++;
    }

    printf("First byte of %d stay on %d position\n", number, count);
    return 0;
}
