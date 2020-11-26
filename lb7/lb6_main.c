#include <stdio.h>
#include "var9lb6.c"
void main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Something goes wrong.\n");
        return 0;
    }
    int s;
    s = myputchar('W');
    printf("The return state is: %c\n", s);

    return;
}
