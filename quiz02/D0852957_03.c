#include <stdio.h>

int ex_or (unsigned a, unsigned b);
void bitPrint(unsigned bit);

int main(){
    unsigned a = 0,b = 0, xored = 0;
    printf("Enter first UNSIGN integer :\n");
    scanf("%d%*c",&a);

    printf("Enter second UNSIGN integer :\n");
    scanf("%d%*c",&b);

    printf("\nInteger a bit pattern:\n");
    bitPrint(a);
    printf("\nInteger b bit pattern:\n");
    bitPrint(b);

    xored = ex_or(a,b);
    printf("\nAfter XOR : \n");
    printf("Integer : %u\n",xored);
    printf("Bit pattern :\n");
    bitPrint(xored);

    return 0;

}

void bitPrint(unsigned bit){
    int counter,rec;
    unsigned short mask = 1;
    mask <<= 15;

    for(counter = 1;counter <=16;counter++){
        printf("%c", bit & mask ? '1' : '0');

        bit <<= 1;

        if (counter == 8){
            printf(" ");
        }
    }
    printf("\n");
}

int ex_or (unsigned a, unsigned b){
    return a ^ b;
}
