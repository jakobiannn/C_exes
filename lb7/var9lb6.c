#include <sys/syscall.h>
#include <stdio.h>
int myputchar(char ch) {
    write(1, &ch, 1);
    return ch;
}
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
