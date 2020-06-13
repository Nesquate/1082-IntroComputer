#include<stdio.h>

int main(){
    unsigned anInteger = 1; 
    unsigned pow = 0;
    int number = 0;

    printf("Enter an number : ");
    scanf("%d",&number);
    getchar();
    printf("Enter 2^pow : ");
    scanf("%d",&pow);
    getchar();

    anInteger = anInteger << pow;

    printf("Result of number*2^pow : %u\n", number*anInteger);

    return 0;
}