#include<stdio.h>

typedef struct{
    int accountnumber;
    char name[30];
    double balance;
}account;

void initialData(account *Ptr);
void readDatafromFile();
void updateDatafromFile();

int main(){
    int select = 0;
    account data1[10];
    
    // Menu select
    while(1){
        printf("Select : \n");
        printf("\t1.) Initial 10 Datas\n");
        printf("\t2.) Read Current Datas\n");
        printf("\t3.) Update Datas\n");
        printf("\t4.) Exit\n");
        printf("[Select 1-4]> ");
        scanf("%d%*c", &select);

        if (select == 1){
            initialData(data1);
            select = 0;
        }
        else if (select == 2){
            readDatafromFile();
            select = 0;
            printf("Press [ENTER] to continue ...");
            getchar();
        }
        else if (select == 3){
            updateDatafromFile();
            select = 0;
        }
        else if (select == 4){
            printf("\nExited.\n");
            break;
        }
        else
        {
            printf("Unknown type!\n");
            printf("Press [ENTER] to continue ...");
            getchar();
        }
    }

    return 0;
}

void initialData(account *Ptr){
    FILE *fPtr;
    int counter = 0, select = 0;

    if ( (fPtr = fopen("database.db", "wb")) == NULL ){
        printf("Cannot open file.\n");
        printf("Press [ENTER] to continue ...");
        getchar();
    }
    else{
        // Enter Datas
        while( counter != 10 ){
            printf ("Enter Account Number, Name and Balance (Space is token)\n> ");
            scanf("%d %[^-0-9] %lf%*c", &(Ptr+counter)->accountnumber, (Ptr+counter)->name, &(Ptr+counter)->balance);
            
            fseek(fPtr, (Ptr+counter)->accountnumber * sizeof(account), SEEK_SET);
            fwrite((Ptr+counter),sizeof(account),1,fPtr);
            
            printf("Do you want to continue ? (1 = yes / 0 = no)");
            scanf("%d%*c", &select);
            if (select == 1){
                select = 0;
                counter++;
            }
            else if (select == 0){
                rewind(fPtr);
                fclose(fPtr);
                break;
            }
            else{
                printf("Wrong type! Process is continued.\n");
                select = 0;
            }
        }
        readDatafromFile();
    }
}

void readDatafromFile(){
    FILE *fPtr;
    account dataRead = {0,"",0};
    int counter = 0, select = 0;

    if ( (fPtr = fopen("database.db", "rb")) == NULL ){
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
            if( dataRead.accountnumber != 0){
                printf("%-20d%-20s%-20.2lf\n", dataRead.accountnumber, dataRead.name, dataRead.balance);
            }
        }
        fclose(fPtr);
    }
}

void updateDatafromFile(){
    FILE *fPtr;
    int accountnumber;
    account dataRead = {0, "", 0};
    readDatafromFile();

    if ( ( fPtr = fopen("database.db","rb+") ) == NULL ){
        printf("Cannot open file.\n");
        printf("Press [ENTER] to continue ...");
        getchar();
    }
    else{
        // Update file
        while(1){
            printf("Enter Account Number (0 = Exit)\n> ");
            scanf("%d%*c", &accountnumber);

            fseek(fPtr, accountnumber*sizeof(account), SEEK_SET);
            fread(&dataRead, sizeof(account),1, fPtr);

            if( dataRead.accountnumber == 0 && accountnumber != 0 ){
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
                printf("%-20d%-20s%-20.2lf\n", dataRead.accountnumber, dataRead.name, dataRead.balance);
                printf("\nEnter new balance : \n> ");
                scanf("%lf%*c",&dataRead.balance);
                fseek(fPtr, accountnumber*sizeof(account), SEEK_SET);
                fwrite(&dataRead, sizeof(account), 1,fPtr);
                
                printf("Update finished.\n");
                printf("Press [ENTER] to continue ...");
                getchar();
            }
        }

    }
}