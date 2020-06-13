#include<stdio.h>
#define SUM(x,y)(\
    {\
    int TOTAL;\
    TOTAL = x + y;\
    TOTAL;\
    }\
)

int main(){
    int a = 0, b = 13;

    printf("SUM of 13 :\n");
    for (a ; a<=6 ; a++){
        printf("%d and %d is %d\n",a,b,SUM(a,b));
        b--;
    }

    return 0;
}