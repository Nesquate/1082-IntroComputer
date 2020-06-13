#include<stdio.h>
#include<string.h>

typedef struct{
    int accountnumber;
    char name[30];
    double balance;
}customers;

int initialData(customers *Ptr); // Initial datas
void printData(customers *Ptr, int n); //Print datas
int readAndUpdate(customers *Ptr); // Read datas from transaction.txt to update data.txt
void storeNewData(customers *Ptr,int n); // Write datas to newdata.txt

int main(){
    int counter = 0;
    customers data[10]; 
    counter = initialData(data);
    printData(data,counter);

    printf("\nPress [ENTER] to continue...");
    getchar();

    counter += readAndUpdate(data);
    printf("\nAfter Transaction : \n");
    printData(data,counter);
    storeNewData(data,counter);

    return 0;
}

int initialData(customers *Ptr){
    int counter = 0;
    FILE *fPtr;
    if ( (fPtr = fopen("data.txt","r")) == NULL ){
        printf("Cannot Open file.\n");
    }
    else{
        fscanf(fPtr, "%*[^\n]");
        while(1){
            fscanf(fPtr, "%d %[^-0-9] %lf", &(Ptr+counter)->accountnumber, (Ptr+counter)->name, &(Ptr+counter)->balance);
            if(feof(fPtr)){
                fclose(fPtr);
                break;
            }
            counter++;
        }
    }
    
    return counter;
}

void printData(customers *Ptr, int n){
    printf("%-20s%-20s%-20s\n","Account ","Name","Balance");
    for(int counter = 0;counter<=n-1;counter++){
        printf("%-20d%-20s%-20.2lf\n",Ptr->accountnumber,Ptr->name,Ptr->balance);
        Ptr++;
    }
}

void storeNewData(customers *Ptr,int n){
    FILE *fPtr;

    if( (fPtr = fopen("newdata.txt", "w")) == NULL){
        printf("File can NOT open.\n");
    }
    else{
        fprintf(fPtr, "%-20s%-20s%-20s\n","Account ","Name","Balance");
        for(int counter = 0;counter<=n-1;counter++){
           fprintf(fPtr, "%-20d%-20s%-20.2lf\n",Ptr->accountnumber,Ptr->name,Ptr->balance);
           Ptr++;
        }
        fclose(fPtr);
    }
}

int readAndUpdate(customers *Ptr){
    FILE *fPtr;
    int tempNumber;
    char tempName[30];
    double tempTransaction;
    int newAccount = 0;
    int counter = 0;
    
    if( (fPtr = fopen("transaction.txt","r")) == NULL){ // open transaction.txt
        printf("Can NOT open file.\n");
    }
    else{
        fscanf(fPtr,"%*[^\n]"); // throw line 1 in transaction.txt
        fscanf(fPtr, "%3d%*[^A-Z]%[^0-9]%lf%*[^\n]",&tempNumber,tempName,&tempTransaction);
        // use for debug
        // printf("[Debug] tempNumber: %d\n",tempNumber);
        // printf("[Debug] tempName : %s\n",tempName);
        // printf("[Debug] tempTransaction : %lf\n",tempTransaction);

        while(1){
        // printf("[Debug] tempNumber: %d\n",tempNumber);
        // printf("[Debug] tempName : %s\n",tempName);
        // printf("[Debug] tempTransaction : %lf\n",tempTransaction);
            if(tempNumber == 100){
                Ptr->balance += tempTransaction;
            }
            else if(tempNumber == 300){
                (Ptr+1)->balance += tempTransaction;
            }
            else if(tempNumber == 500){
                (Ptr+2)->balance += tempTransaction;
            }
            else if(tempNumber == 700){
                (Ptr+3)->balance += tempTransaction;
            }
            else{
                newAccount++;
                (Ptr+3+newAccount)->accountnumber = tempNumber;
                strcpy((Ptr+3+newAccount)->name,tempName);
                (Ptr+3+newAccount)->balance = tempTransaction;
            }
            if(feof(fPtr)){
                fclose(fPtr);
                break;
            }
            fscanf(fPtr, "%3d%*[^A-Z]%[^0-9]%lf%*[^\n]",&tempNumber,tempName,&tempTransaction);
        }
    }

    return newAccount;
}
