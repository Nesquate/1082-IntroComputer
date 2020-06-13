#include <stdio.h>

void bitPrint(unsigned bit);
void guessBit(unsigned bit);

int main(){
    unsigned anNumber = 0;

    printf("Enter an UNSIGN integer :\n");
    scanf("%d%*c", &anNumber);
    bitPrint(anNumber);
    guessBit(anNumber);

    return 0;

}

void bitPrint(unsigned bit){
    int counter,rec;
    unsigned short mask = 1;
    mask <<= 15;

    printf("\nBit pattern print :\n");
    for(counter = 1;counter <=16;counter++){
        printf("%c", bit & mask ? '1' : '0');

        bit <<= 1;

        if (counter == 8){
            printf(" ");
        }
    }
    printf("\n");
}

void guessBit(unsigned bit){
    unsigned short mask = 1;
    mask <<= 1;
    printf("The 2nd bit is %c\n", bit & mask ? '1' : '0');
    mask <<= 2;
    printf("The 4th bit is %c\n", bit & mask ? '1' : '0');
    mask <<= 2;
    printf("The 6th bit is %c\n", bit & mask ? '1' : '0');

}
