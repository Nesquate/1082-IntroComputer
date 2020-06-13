#include<stdio.h>
#define SUM(x,y)(\
    {\
    int TOTAL;\
    TOTAL = x + y;\
    TOTAL;\
    }\
)

int main(){
    int a=0,b=0;
    printf("Please enter two integer numbers :\n");
    scanf("%d %d",&a,&b);

    printf("Sum is : %d\n",SUM(a,b));

    return 0;
}