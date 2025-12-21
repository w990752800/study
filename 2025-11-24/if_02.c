#include<stdio.h>

int main() {

    int a = 0;
    int b = 10;

    if(a == b) {

        a++;
        b--;

    } else {

        a = a + 2;
        b = b + 2;
    }

    printf("%d, %d \n", a, b);

    return 0;
}