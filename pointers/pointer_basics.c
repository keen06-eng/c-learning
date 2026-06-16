#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;

    printf("Value: %d\n", *ptr);
    printf("Address: %p\n", ptr);

    *ptr = 100;
    printf("New value: %d\n", num);

    return 0;
}
