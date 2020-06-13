#include<stdio.h>

typedef struct{
    int toolID;
    char name[30];
    int quantity;
    double cost;
    double per;
}tools;

void initialData(tools *Ptr);
void readDatafromFile();
void updateDatafromFile();

int main(){
    int select = 0;
    tools data1[100];
    
    // Menu select
    while(1){
        printf("Select : \n");
        printf("\t1.) Initial Datas\n");
        printf("\t2.) Read Current Datas\n");
        printf("\t3.) Update Datas\n");
        printf("\t4.) Exit\n");
        printf("[Select 1-4]> ");
        scanf("%d%*c", &select);

        if (select == 1){
            initialData(data1);
            select = 0;
            printf("Press [ENTER] to continue ...");
            getchar();
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
            printf("Press [ENTER] to continue ...");
            getchar();
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

void initialData(tools *Ptr){
    FILE *fPtr;
    int counter = 0, select = 0;

    if ( (fPtr = fopen("tooldatabase.db", "wb")) == NULL ){
        printf("Cannot open file.\n");
        printf("Press [ENTER] to continue ...");
        getchar();
    }
    else{
        // Enter Datas
        while(1){
            printf ("Enter Tools ID, Name, Quantity and Cost (Space is token)\n> ");
            scanf("%d %[^-0-9] %d %lf%*c", &(Ptr+counter)->toolID, (Ptr+counter)->name, &(Ptr+counter)->quantity, &(Ptr+counter)->cost);
            (Ptr+counter)->per = (Ptr+counter)->cost / (Ptr+counter)->quantity;
            
            fseek(fPtr, (Ptr+counter)->toolID * sizeof(tools), SEEK_SET);
            fwrite((Ptr+counter),sizeof(tools),1,fPtr);
            
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
    tools dataRead = {0,"",0,0,0};
    int counter = 0, select = 0;

    if ( (fPtr = fopen("tooldatabase.db", "rb")) == NULL ){
        printf("Cannot open file.\n");
        printf("Press [ENTER] to continue ...");
        getchar();
    }
    else{
        // read file
        printf("%-20s%-20s%-20s%-20s%-20s\n","Tool ID","Tool Name", "Quantity", "Cost", "Cost/per");

        while(1){
            fread(&dataRead, sizeof(tools), 1, fPtr);
            if (feof(fPtr)){
                break;
            }
            if( dataRead.toolID != 0){
                printf("%-20d%-20s%-20d%-20.2lf%-20.2lf\n", dataRead.toolID, dataRead.name,dataRead.quantity , dataRead.cost, dataRead.per);
            }
        }
        fclose(fPtr);
    }
}

void updateDatafromFile(){
    FILE *fPtr;
    int accountnumber;
    tools dataRead = {0, "",0 , 0, 0};
    readDatafromFile();

    if ( ( fPtr = fopen("tooldatabase.db","rb+") ) == NULL ){
        printf("Cannot open file.\n");
        printf("Press [ENTER] to continue ...");
        getchar();
    }
    else{
        // Update file
        while(1){
            printf("Enter Tool ID (0 = Exit)\n> ");
            scanf("%d%*c", &accountnumber);

            fseek(fPtr, accountnumber*sizeof(tools), SEEK_SET);
            fread(&dataRead, sizeof(tools),1, fPtr);

            if( dataRead.toolID == 0 && accountnumber != 0 ){
                printf("Account is not existed.\n");
                printf("Press [ENTER] to continue ...");
                getchar();
            }
            else if(accountnumber == 0){
                fclose(fPtr);
                printf("Update file is end.\n");
                break;
            }
            else{
                printf("%-20s%-20s%-20s%-20s%-20s\n","Tool ID","Tool Name", "Quantity", "Cost", "Cost/per");
                printf("%-20d%-20s%-20d%-20.2lf%-20.2lf\n", dataRead.toolID, dataRead.name,dataRead.quantity , dataRead.cost, dataRead.per);
                printf("\nEnter new Quantity : \n> ");
                scanf("%d%*c",&dataRead.quantity);
                dataRead.cost = dataRead.quantity * dataRead.per;
                fseek(fPtr, accountnumber*sizeof(tools), SEEK_SET);
                fwrite(&dataRead, sizeof(tools), 1,fPtr);
                
                printf("Update finished.\n");
            }
        }

    }
}