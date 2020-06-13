#include<stdio.h>
#include<string.h>

struct customer {
    char lastname[15];
    char firstname[15];
    unsigned int customerNumber;
    struct {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
} customerRecord, *customerPtr;

int main(){
    customerPtr = &customerRecord;
    struct customer *addPtr;
    
    strcpy(customerRecord.lastname, "Smith");
    strcpy(customerPtr->firstname, "Andy");
    customerRecord.customerNumber = 201;
    strcpy(customerPtr->personal.phoneNumber, "09003838");
    strcpy(customerRecord.personal.address, "101 Pretty Way, Bigcity, SmallState");
    strcpy(customerPtr->personal.zipCode, "99999");
    
    printf("customerRecord.lastname : %s\n",customerRecord.lastname);
    printf("customerPtr->firstname : %s\n", customerPtr->firstname);
    printf("customerRecord.customerNumber : %d\n", customerRecord.customerNumber);
    printf("customerPtr->personal.phoneNumber : %d\n", customerPtr->personal.phoneNumber);
    printf("customerRecord.personal.address : %s\n", customerRecord.personal.address);
    printf("customerPtr->personal.zipCode : %s\n", customerPtr->personal.zipCode);

    return 0;
}