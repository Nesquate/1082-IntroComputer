/*
筆記用的檔案
理論上這個不應該外流才對
參考檔案：fig12_08.c
by Nesquate
*/

/*
stack 我會把它當作反著做的 Linked List
所以在新增資料的時候，指標的地方要指向舊的 struct 的地址
 */

// 一如往常的宣告
#include <stdio.h>
#include <stdlib.h>

// 建立 stack 結構                 
struct stackNode {                                   
   int data; // 當前資料           
   struct stackNode *nextPtr; // 下一個 pointer 在哪裡
};

// 這邊藏了一個星號，我只能用幹你娘來形容這個慘案
typedef struct stackNode StackNode; 
typedef StackNode *StackNodePtr; 

// prototypes
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

// big bang
int main(void)
{ 
   StackNodePtr stackPtr = NULL; //一開始要是空的，表示 stack 的結尾
   int value; // 這裡是存使用者輸入的值
 
   instructions(); // display the menu
   printf("%s", "? ");
   unsigned int choice; // user's menu choice
   scanf("%u", &choice);

   // while user does not enter 3
   while (choice != 3) { 

      switch (choice) { 
         // push value onto stack
         case 1:      
            printf("%s", "Enter an integer: ");
            scanf("%d", &value);
            push(&stackPtr, value);
            printStack(stackPtr);
            break;
         // pop value off stack
         case 2:      
            // if stack is not empty
            if (!isEmpty(stackPtr)) {
               printf("The popped value is %d.\n", pop(&stackPtr));
            } 

            printStack(stackPtr);
            break;
         default:
            puts("Invalid choice.\n");
            instructions();
            break;
      } // end switch

      printf("%s", "? ");
      scanf("%u", &choice);
   } 

   puts("End of run.");
} 

// display program instructions to user
void instructions(void)
{ 
   puts("Enter choice:\n"
      "1 to push a value on the stack\n"
      "2 to pop a value off the stack\n"
      "3 to end program");
} 

// push function 本體，怕
void push(StackNodePtr *topPtr, int info)
{ 
   StackNodePtr newPtr = malloc(sizeof(StackNode)); // 開個新空間，不然沒地方放東西

   // push 判定，新的值不等於 NULL 就跑一下ㄅ
   if (newPtr != NULL) {           
      newPtr->data = info;  // 新數字丟進去一下

      // 新空間的下一個值要指向舊資料的地址
      // 這樣才有 stack 的 feel         
      newPtr->nextPtr = *topPtr; 
      // 開頭變成新空間的地址，這樣我才可以往「前」堆疊
      *topPtr = newPtr;              
   }                     
   else { // no space available
      printf("%d not inserted. No memory available.\n", info);
   } 
} 

// pop function 本體，也是怕爆
int pop(StackNodePtr *topPtr)
{ 
   StackNodePtr tempPtr = *topPtr; // 先暫存最前面的資料地址
   
   // 因應 return 值是要丟出要丟掉的值所以就這樣寫
   // 如果不要 return 這裡可以連同 return 一起丟掉
   int popValue = (*topPtr)->data;  

   *topPtr = (*topPtr)->nextPtr; //把下一個資料的地址挪到最前面
   free(tempPtr);  // 最前面的資料，我丟，不 free 的話系統不會釋放這個記憶體，到時候電腦就 GG
   return popValue; // 回傳被丟掉的值 （rip）
} 

// print the stack
void printStack(StackNodePtr currentPtr)
{ 
   // if stack is empty
   if (currentPtr == NULL) {
      puts("The stack is empty.\n"); // 空的就不要印東西了
   } 
   else { 
      puts("The stack is:");

      // 開東西來印
      while (currentPtr != NULL) { 
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;  // 移動到下一個地址
      } 

      puts("NULL\n");
   } 
} 

// return 1 if the stack is empty, 0 otherwise
int isEmpty(StackNodePtr topPtr)
{ 
   return topPtr == NULL;
} 


