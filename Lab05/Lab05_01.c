#include<stdio.h>
#include<ctype.h>

struct customer
{
int customerNumber;
char lastName[15];
char firstName[15];
char phoneNumber[11];
double balance;
};

int main(){
    int status = 0;
    int scansta = 0;
    struct customer data;
    
    scansta = scanf("%[a-z ]", &data.firstName);
    getchar();
    printf("%d\n",scansta);
    printf("%s\n",data.firstName);

    return 0;
}