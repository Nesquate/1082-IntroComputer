#include<stdio.h>

struct customer{
    int account_number;
    char name[30];
    double balance;
};

typedef struct customer account;

void readDatafromFile();
void updateDatafromFile();

int main(){
    account data[20];
    // readDatafromFile();
    updateDatafromFile();

}

void readDatafromFile(){
    FILE *fPtr;
    account dataRead = {0,"",0};
    int counter = 0, select = 0;

    if ( (fPtr = fopen("customer.dat", "rb")) == NULL ){
        printf("Cannot open file.\n");
        printf("Press [ENTER] to continue ...");
        getchar();
    }
    else{
        // read file
        printf("%-20s%-20s%-20s\n","Account","Name", "Balance");

        while(1){
            fread(&dataRead, sizeof(account), 1, fPtr);
            if (feof(fPtr)){
                break;
            }
            if( dataRead.account_number != 0){
                printf("%-20d%-20s%-20.2lf\n", dataRead.account_number, dataRead.name, dataRead.balance);
            }
        }
        fclose(fPtr);
    }
}

void updateDatafromFile(){
    FILE *fPtr;
    int accountnumber;
    account dataRead = {0, "", 0};
    // readDatafromFile();

    if ( ( fPtr = fopen("customer.dat","rb+") ) == NULL ){
        printf("Cannot open file.\n");
        printf("Press [ENTER] to continue ...");
        getchar();
    }
    else{
        // Update file
        while(1){
            printf("Enter Account Number (0 = Exit)\n> ");
            scanf("%d%*c", &accountnumber);

            fseek(fPtr, (accountnumber-1)*sizeof(account), SEEK_SET);
            fread(&dataRead, sizeof(account),1, fPtr);

            if( dataRead.account_number == 0 && accountnumber != 0 ){
                printf("Account is not existed.\n");
                printf("Press [ENTER] to continue ...");
                getchar();
            }
            else if(accountnumber == 0){
                fclose(fPtr);
                printf("Update file is end.\n");
                printf("Press [ENTER] to continue ...");
                getchar();
                break;
            }
            else{
                printf("%-20s%-20s%-20s\n","Account","Name", "Balance");
                printf("%-20d%-20s%-20.2lf\n", dataRead.account_number, dataRead.name, dataRead.balance);
                printf("\nEnter new balance : \n> ");
                scanf("%lf%*c",&dataRead.balance);
                fseek(fPtr, (accountnumber-1)*sizeof(account), SEEK_SET);
                fwrite(&dataRead, sizeof(account), 1,fPtr);
                
                fseek(fPtr, (accountnumber-1)*sizeof(account), SEEK_SET);
                fread(&dataRead, sizeof(account),1, fPtr);
                printf("%-20s%-20s%-20s\n","Account","Name", "Balance");
                printf("%-20d%-20s%-20.2lf\n", dataRead.account_number, dataRead.name, dataRead.balance);
                printf("Update finished.\n");
                printf("Press [ENTER] to continue ...");
                getchar();
            }
        }

    }
}
