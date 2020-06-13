#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct node
{
    char string[15];
    struct node *nptr;
};

typedef struct node ListNode; 
typedef ListNode *ListNodePtr; 

void insert(ListNodePtr *sPtr, char *value);
void delete(ListNodePtr *sPtr, char *value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);

int main(){
    FILE *fptr;
    ListNodePtr startPtr = NULL; 
    int counter = 0;
    

    if( (fptr = fopen("linked_list.txt", "r")) == NULL ){
        printf("\"linked_list.txt\" does not exist.\n");
    }
    else{
       char tempValue[24][15] = {0};
        while(!feof(fptr)){
            
            fscanf(fptr,"%s",&tempValue[counter][0]);
            insert(&startPtr, &tempValue[counter][0]); 
            counter++;
        }
        fclose(fptr);
        printList(startPtr);
        
        printf("\nPress [ENTER] to continue...");
        getchar();

         srand(time(NULL));
         int a = (rand() % 24);
         printf("\nDelete : %s in %d \n\n",tempValue[a], a+1);
         delete(&startPtr, &tempValue[a][0]);
         printList(startPtr);

      printf("\nPress [ENTER] to continue...");
        getchar();

    }
}

void insert(ListNodePtr *sPtr, char *value)
{ 
   ListNodePtr newPtr = malloc(sizeof(ListNode)); // create node

   if (newPtr != NULL) { // is space available
      strcpy(newPtr->string, value); // place value in node
      newPtr->nptr = NULL; // node does not link to another node
      // printf("Debug : newPtr->string  => %s\n", newPtr->string);

      ListNodePtr previousPtr = NULL;
      ListNodePtr currentPtr = *sPtr;
    
     while (currentPtr != NULL) { // 如果目前的指標不是空的
         previousPtr = currentPtr; // 目前的變成舊的         
         currentPtr = currentPtr->nptr; // 新的變成目前的 
      }                                          

      // 如果舊的 node 地址是空的 
      // 就代表目前是在最前面
      // 也就是說我新的值（比較小）
      // 應該要插在這裡
      if (previousPtr == NULL) { 
         newPtr->nptr = *sPtr;
         *sPtr = newPtr;
      } 
      // 如果不是這種狀況，就代表我跑到中間或是尾巴
      // 那把前一個 node 的指標填入新的 node 的地址，
      // 新 node 的指標插入目前 node 的地址
      else { 
         previousPtr->nptr = newPtr;
         newPtr->nptr = currentPtr; // 注意，這裡插入的有可能是 NULL，代表我已經到尾巴ㄌ
      } 
  
   } 
   else {
      printf("No memory available.\n");
   } 
} 

// delete a list element
void delete(ListNodePtr *sPtr, char *value)
{ 
   // delete first node if a match is found
   if ( (strcmp(value,(*sPtr)->string)) == 0) { 
      ListNodePtr tempPtr = *sPtr; // hold onto node being removed
      *sPtr = (*sPtr)->nptr; // de-thread the node
      free(tempPtr); // free the de-threaded node
   } 
   else { 
      ListNodePtr previousPtr = *sPtr;
      ListNodePtr currentPtr = (*sPtr)->nptr;

      // loop to find the correct location in the list
      while (currentPtr != NULL && strcmp(value,currentPtr->string) != 0) { 
         previousPtr = currentPtr; // walk to ...  
         currentPtr = currentPtr->nptr; // ... next node  
      } 

      // delete node at currentPtr
      if (currentPtr != NULL) { 
         ListNodePtr tempPtr = currentPtr;
         previousPtr->nptr = currentPtr->nptr;
         free(tempPtr);
      } 
   } 
} 

// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{ 
   return sPtr == NULL;
} 

// print the list
void printList(ListNodePtr currentPtr)
{ 
   // if list is empty
   if (isEmpty(currentPtr)) {
      puts("List is empty.\n");
   } 
   else { 
      puts("The list is:");

      // while not the end of the list
      while (currentPtr != NULL) { 
         printf("%s-->", currentPtr->string);
         currentPtr = currentPtr->nptr;   
      } 

      printf("NULL\n");
   } 
}
