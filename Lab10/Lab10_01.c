#include<stdio.h>
#define COMPARE(X,Y) (\
    {\
       int C;\
       if (X > Y){\
           C =  X;\
        }\
        else if (X < Y){\
            C = Y;\
        }\
        else{\
            C = -1;\
        }\
        C;\
    }\
)

int main(){
    int a = 0,b = 0;
    printf("Enter a and b (space separate) : \n");
    scanf ("%d %d",&a,&b);

    printf("Result : %d ( -1 is equal)\n", COMPARE(a,b));

    return 0;
}