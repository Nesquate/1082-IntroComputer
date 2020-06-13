#include<stdio.h>
#define SUMMARY(ARRAY,AMOUNT)(\
    {\
        int TOTAL = 0, I = 0;\
        for (I = 0;I <= AMOUNT;I++){\
            TOTAL += ARRAY[I];\
        }\
        TOTAL;\
    }\
)

int main(){
    FILE *fptr; // 讀檔指標
    int array[1000] = {0}, counter = 0;
    if ( (fptr = fopen("array.txt","r"))  == NULL ){
        printf("Can not open file.\n");
    }
    else{
        while(1){ // 防止多讀一次的寫法
            fscanf(fptr,"%d%*[^ ]",&array[counter]); // 這是一個一個數字讀來的大致寫法，數字放到 array 去
            if(feof(fptr)){
                fclose(fptr);
                break;
            }
            counter++;
        }
    }
    printf("Sum = %d\n", SUMMARY(array,counter));

    return 0;
}