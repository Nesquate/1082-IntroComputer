/*
筆記用的檔案
理論上這個不應該外流才對
參考檔案：fig12_19.c
by Nesquate
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 建立樹                      
struct treeNode {                                           
   struct treeNode *leftPtr; // 左邊
   int data; // 中間                     
   struct treeNode *rightPtr; // 右邊
}; 

// 我已經懶得罵了
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr; 

// prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

// function main begins program execution
int main(void)
{ 
   TreeNodePtr rootPtr = NULL; // 初始化

   srand(time(NULL));  // 使用隨機填入
   puts("The numbers being placed in the tree are:");

   // 填數字進去
   for (unsigned int i = 1; i <= 10; ++i) { 
      int item = rand() % 15;
      printf("%3d", item);
      insertNode(&rootPtr, item);
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
} 

// 插入的 function
void insertNode(TreeNodePtr *treePtr, int value)
{ 
   // 沒有空間就要開空間
   if (*treePtr == NULL) {   
      *treePtr = malloc(sizeof(TreeNode));

      // 開完空間塞數字
      if (*treePtr != NULL) { 
         (*treePtr)->data = value;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      } 
      else { // 記憶體確診的時候
         printf("%d not inserted. No memory available.\n", value);
      } 
   } 
   else { // 有空間的話
      // 比大小
      if (value < (*treePtr)->data) {  // 比中間小放左邊   
         insertNode(&((*treePtr)->leftPtr), value);   
      }                                         

      // 比中間大放右邊
      else if (value > (*treePtr)->data) {                 
         insertNode(&((*treePtr)->rightPtr), value);     
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
      inOrder(treePtr->leftPtr);         
      printf("%3d", treePtr->data);      
      inOrder(treePtr->rightPtr);        
   }                           
} 

// preOrder Function
void preOrder(TreeNodePtr treePtr)
{ 
   // 遞迴 function
   // 先印中間
   // 然後往左下探後再往右下探
   if (treePtr != NULL) {                
      printf("%3d", treePtr->data);      
      preOrder(treePtr->leftPtr);        
      preOrder(treePtr->rightPtr);       
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
      postOrder(treePtr->leftPtr);       
      postOrder(treePtr->rightPtr);      
      printf("%3d", treePtr->data);      
   }                           
} 
