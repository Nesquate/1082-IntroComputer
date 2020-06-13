#include <stdio.h>

void packCharacters(char first,char second);
void bitPrint(unsigned bit);

int main (){
    char f,s;

    printf("Enter First Character : ");
    scanf("%c",&f);
    getchar();
    printf("Enter Second Character : ");
    scanf("%c",&s);
    getchar();

    packCharacters(f,s);

    return 0;
}

void packCharacters(char first,char second){
    unsigned short result;

    printf("First : %c\n",first);
    printf("Second : %c\n",second);

    printf("First character in 16bit : \n");
    bitPrint((unsigned)first);
    printf("Second character in 16bit : \n");
    bitPrint((unsigned)second);

    result = first;
    result <<= 8;
    result = result | second;

    printf("Result of Pack Characters : \n");
    bitPrint((unsigned)result);
}

void bitPrint(unsigned bit){
    int counter,rec;
    unsigned short mask = 1;
    mask <<= 15;
    // printf("[Debug] bit = %hu\n", bit);
    // printf("[Debug] mask = %hu\n", mask);
    for(counter = 1;counter <=16;counter++){
        printf("%c", bit & mask ? '1' : '0');

        bit <<= 1;

        if (counter == 8){
            printf(" ");
        }
    }
    printf("\n");
}