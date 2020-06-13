#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int item;
    struct node *lptr;
    struct node *rptr;
};

typedef struct node TreeNode;
typedef TreeNode *TreeNodePtr; 

void insertNode(TreeNodePtr *treePtr, int value)
{ 
   // 沒有空間就要開空間
   if (*treePtr == NULL) {   
      *treePtr = malloc(sizeof(TreeNode));

      // 開完空間塞數字
      if (*treePtr != NULL) { 
         (*treePtr)->item = value;
         (*treePtr)->lptr = NULL;
         (*treePtr)->rptr = NULL;
      } 
      else { // 記憶體確診的時候
         printf("%d not inserted. No memory available.\n", value);
      } 
   } 
   else { // 有空間的話
      // 比大小
      if (value < (*treePtr)->item) {  // 比中間小放左邊   
         insertNode(&((*treePtr)->lptr), value);   
      }                                         

      // 比中間大放右邊
      else if (value > (*treePtr)->item) {                 
         insertNode(&((*treePtr)->rptr), value);     
      }                                        
      else { // 等於的話就當作重複忽略它，但還是要印出來
         printf("%s", "dup");
      } 
   } 
} 

// inOrder Function
void inOrder(TreeNodePtr treePtr)
{ 
   // 遞迴 function
   // 左邊通通印完 -> 印中間 -> 右邊通通印完
   // 但是印右邊的時候還是左邊下探優先
   if (treePtr != NULL) {                
      inOrder(treePtr->lptr);         
      printf("%3d", treePtr->item);      
      inOrder(treePtr->rptr);        
   }                           
} 

// preOrder Function
void preOrder(TreeNodePtr treePtr)
{ 
   // 遞迴 function
   // 先印中間
   // 然後往左下探後再往右下探
   if (treePtr != NULL) {                
      printf("%3d", treePtr->item);      
      preOrder(treePtr->lptr);        
      preOrder(treePtr->rptr);       
   }                           
} 

// postOrder Function
void postOrder(TreeNodePtr treePtr)
{ 
   // 遞迴 function
   // 先印左邊
   // 再印右邊
   // 最後印中間
   if (treePtr != NULL) {                
      postOrder(treePtr->lptr);       
      postOrder(treePtr->rptr);      
      printf("%3d", treePtr->item);      
   }                     
} 



int main(){
    TreeNodePtr rootPtr = NULL; 
    TreeNodePtr rootPtr2 = NULL;
    FILE *fptr;
    int temp[50];
    int counter = 0;

    if ( ( fptr = fopen("binary_tree.txt", "r") ) == NULL ){
        printf("Can't not find \"binary_tree.txt\".\n");
    }
    else{
        while(1){
            
            fscanf(fptr ,"%d%*[ ]", &temp[counter]);
            insertNode(&rootPtr, temp[counter]);
            
            if (feof(fptr)){
                fclose(fptr);
                printf("Press [ENTER] to continue...");
                getchar();
                break;
            }
            counter++;
        }
        // preOrder
        puts("\n\nThe preOrder traversal is:");
        preOrder(rootPtr);

        // inOrder
        puts("\n\nThe inOrder traversal is:");
        inOrder(rootPtr);

        // postOrder
        puts("\n\nThe postOrder traversal is:");
        postOrder(rootPtr);
        printf("\n"); 

        printf("Press [ENTER] to continue...");
        getchar();

        int random = 0;
        srand(time(NULL));
        random = rand() % counter;

        printf("\nSelected integer : %d\n", temp[random]);
        printf("Press [ENTER] to continue...");
        getchar();

        for(int i = 0; i <= counter; i++){
           if(temp[i] != temp[random]){
              insertNode(&rootPtr2, temp[i]);
           }
        }

        // preOrder
        puts("\n\nThe preOrder traversal is:");
        preOrder(rootPtr2);

        // inOrder
        puts("\n\nThe inOrder traversal is:");
        inOrder(rootPtr2);

        // postOrder
        puts("\n\nThe postOrder traversal is:");
        postOrder(rootPtr2);
        printf("\n"); 
    }
}
