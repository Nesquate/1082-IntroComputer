#include<stdio.h>

int main(){
    int *ptr[100];
    double *ptrsize;

    printf("%ld\n",sizeof(ptr));
    printf("%ld\n",sizeof(ptrsize));
    return 0;
}