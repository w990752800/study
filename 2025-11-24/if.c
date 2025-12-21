
#include<stdio.h>

int main() {

    int a = 0;
    int b = 0;

    int max = 0;


    printf("请输入两个数：");
    scanf("%d %d", &a, &b);


    if(a > b) {


        max = a;
    }

    if(b > a) {
        max = b;
    }



    printf("max = %d \n", max);




    return 0;
}


