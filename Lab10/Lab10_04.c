#include<stdio.h>
#define PRINT(STRING)(\
    {\
        printf(#STRING "\n" );\
    }\
)

int main(){
    PRINT(Hey! oh haha!);

    return 0;
}