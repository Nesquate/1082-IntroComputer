#include<stdio.h>

int main(){
    int a = 0 ,b = 0,c;
    printf("Enter two integers : (Space is token)\n");
    c = scanf("%d %d",&a,&b);

    printf("Scanf return value : %d\n", c);
    printf("a = %d\n b = %d\n",a,b);
}