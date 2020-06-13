#include<stdio.h>
#include<string.h>

struct employee{
    int id;
    char *lastName;
    char *firstName;
    char gender;
    int age;
    float salary;
};

typedef struct employee ep;
int readFiles(ep *Ptr);
void printData(ep*Ptr, int n);
void storeNewData(ep *Ptr,int n);

int main(){
    ep data[20];
    int counter = 0;

    counter = readFiles(data);
    printData(data, counter);
    storeNewData(data, counter);

    return 0;
}

int readFiles(ep *Ptr){
    FILE *fPtr;
    // ep temp = {0, "","", "", 0,0};
    int newAccount = 0;
    int counter = 0;
    char lastName[30], firstName[30];
    
    if( (fPtr = fopen("input.txt","r")) == NULL){ // open transaction.txt
        printf("Can NOT open file.\n");
    }
    else{
        fscanf(fPtr,"%*[^\n]");
        // fscanf(fPtr, "%d%*[^A-Z]%[^ ]%*[^A-Z]%[^ ]%*[^A-Z]%c%*[^0-9]%d%*[^0-9]%f%*[^\n]%*c",
        // &Ptr->id, lastName, firstName, &Ptr->gender, &Ptr->age, &Ptr->salary);
        // use for debug
        // printf("[Debug] id: %d\n",Ptr->id);
        // printf("[Debug] lastName : %s\n",lastName);
        // printf("[Debug] lastName : %s\n",firstName);
        // printf("[Debug] lastName : %c\n",Ptr->gender);
        // printf("[Debug] lastName : %d\n",Ptr->age);
        // printf("[Debug] lastName : %f\n",Ptr->salary);

        while(1){
            if(feof(fPtr)){
                fclose(fPtr);
                break;
            }
            fscanf(fPtr, "%d%*[^A-Z]%[^ ]%*[^A-Z]%[^ ]%*[^A-Z]%c%*[^0-9]%d%*[^0-9]%f%*[^\n]",
            &Ptr->id, Ptr->lastName, Ptr->firstName, &Ptr->gender, &Ptr->age, &Ptr->salary);
            strcpy(Ptr->lastName,lastName);
            strcpy(Ptr->firstName,firstName);
            
            newAccount ++;
        }
    }
    return newAccount;
}

void printData(ep*Ptr, int n){
    printf("%-20s%-20s%-20s%-20s%-20s%-20s\n","ID ","Last Name","First Name", "Gender", "Age", "Salary");
    for(int counter = 0;counter<=n-1;counter++){
        printf("%-20d%-20s%-20s%-20c%-20d%-20.2f\n",Ptr->id,Ptr->lastName,Ptr->firstName,Ptr->gender,Ptr->age,Ptr->salary);
        Ptr++;
    }
}

void storeNewData(ep *Ptr,int n){
    FILE *fPtr;

    if( (fPtr = fopen("employee.dat", "w")) == NULL){
        printf("File can NOT open.\n");
    }
    else{
        fprintf(fPtr, "%-20s%-20s%-20s%-20s%-20s%-20s\n","ID ","Last Name","First Name", "Gender", "Age", "Salary");
        for(int counter = 0;counter<=n-1;counter++){
           fprintf(fPtr, "%-20d%-20s%-20s%-20c%-20d%-20.2f\n",Ptr->id,Ptr->lastName,Ptr->firstName,Ptr->gender,Ptr->age,Ptr->salary);
           Ptr++;
        }
        fclose(fPtr);
    }
}