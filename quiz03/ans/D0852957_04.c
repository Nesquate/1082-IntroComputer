#include<stdio.h>
#include<stdlib.h> // for malloc and free

// self-referential structure                     
struct node {                                   
   int data; // define data as an int             
   struct mode *nptr; // stackNode pointer
};

typedef struct node StackNode; // synonym for struct stackNode
typedef StackNode *StackNodePtr; // synonym for StackNode*

void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);

int main(){
    FILE *fptr;
    StackNodePtr stackPtr = NULL; 
    int tempValue = 0; // for store integers

    if( (fptr = fopen("stack.txt", "r")) == NULL ){
        printf("\"stack.txt\" does not exist.\n");
    }
    else{
        // read integers to struct
        while(1){
            fscanf(fptr,"%d%*[ ]",&tempValue);
            push(&stackPtr, tempValue);
            

            if (feof(fptr)){
                printStack(stackPtr);
                printf("Press [ENTER] to continue...");
                getchar();
                fclose(fptr);
                break;
            }
        }

        int tempArray[3];

        tempArray[0] = pop(&stackPtr);
        printf("\nPop First :\n");
        printStack(stackPtr);
        tempArray[1] = pop(&stackPtr);
        printf("\nPop Second :\n");
        printStack(stackPtr);

        printf("Press [ENTER] to continue...");
        getchar();

        while(!isEmpty(stackPtr)){
            pop(&stackPtr);
        }
        if(isEmpty(stackPtr)){
            printf("\nStack Erased.\n");
            printf("(Prevent memory leak)\n");
        }
    }
}

void push(StackNodePtr *topPtr, int info)
{ 
   StackNodePtr newPtr = malloc(sizeof(StackNode));

   // insert the node at stack top
   if (newPtr != NULL) {           
      newPtr->data = info;           
      newPtr->nptr = *topPtr;     
      *topPtr = newPtr;              
   }                     
   else { // no space available
      printf("%d not inserted. No memory available.\n", info);
   } 
}

int pop(StackNodePtr *topPtr)
{ 
   StackNodePtr tempPtr = *topPtr;             
   int popValue = (*topPtr)->data;  
   *topPtr = (*topPtr)->nptr;
   free(tempPtr);               
   return popValue;
} 

void printStack(StackNodePtr currentPtr)
{ 
   // if stack is empty
   if (currentPtr == NULL) {
      puts("The stack is empty.\n");
   } 
   else { 
      puts("The stack is:");

      // while not the end of the stack
      while (currentPtr != NULL) { 
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->nptr;
      } 

      puts("NULL\n");
   } 
} 

int isEmpty(StackNodePtr topPtr)
{ 
   return topPtr == NULL;
} 