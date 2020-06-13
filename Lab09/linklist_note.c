/*
筆記用的檔案
理論上這個不應該外流才對
參考檔案：fig12_03.c
by Nesquate
*/

/*
Link List 的程式範本
*/

// 一如往常的宣告
#include <stdio.h>
#include <stdlib.h>

// 宣告結構                    
struct listNode {                                      
   char data;  // 要存的資料
   struct listNode *nextPtr; // 下一筆資料的指標
}; 

// 一樣是幹你娘不解釋
typedef struct listNode ListNode; 
typedef ListNode *ListNodePtr; 

// prototypes
void insert(ListNodePtr *sPtr, char value); // 插入
char delete(ListNodePtr *sPtr, char value); // 刪除
int isEmpty(ListNodePtr sPtr); // 檢查是否為空
void printList(ListNodePtr currentPtr); // 印出來
void instructions(void); // Menu

int main(void)
{ 
   ListNodePtr startPtr = NULL; // 設定一個空指標
   char item; // 放進去的字元

   instructions(); // display the menu
   printf("%s", "? ");
   unsigned int choice; // user's choice
   scanf("%u", &choice);

   // loop while user does not choose 3
   while (choice != 3) { 

      switch (choice) { 
         case 1:   // insert item in list
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            insert(&startPtr, item); // 插入一個 '字元' 進去
            printList(startPtr);
            break;
         case 2:   // delete an element
            // 先檢查是不是空的
            if (!isEmpty(startPtr)) {  
               printf("%s", "Enter character to be deleted: ");
               scanf("\n%c", &item);

               // 如果找到輸入的字元就移除
               if (delete(&startPtr, item)) { // 如果順利執行就印出結果
                  printf("%c deleted.\n", item);
                  printList(startPtr);
               } 
               else {
                  printf("%c not found.\n\n", item); // 否則噴找不到的訊息
               } 
            } 
            else {
               puts("List is empty.\n");
            } 

            break;
         default:
            puts("Invalid choice.\n");
            instructions();
            break;
      } // end switch

      printf("%s", "? ");
      scanf("%u", &choice);
   } 
   printList(startPtr);
   puts("End of run.");
} 

// display program instructions to user
void instructions(void)
{ 
   puts("Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end.");
} 

// 插入的程式
void insert(ListNodePtr *sPtr, char value)
{ 
   ListNodePtr newPtr = malloc(sizeof(ListNode)); // 開一個新空間給我

   if (newPtr != NULL) { // 理論上新開的空間要是空的，除非記憶體爆炸ㄌ
      newPtr->data = value; // 放東西到新的空間去
      newPtr->nextPtr = NULL; // 目前這個 node 不連結到其他 node ，等之後再說

      ListNodePtr previousPtr = NULL; // 存之前 node 的地址，但這裡目前還沒有
      ListNodePtr currentPtr = *sPtr; // 存現在 node 的地址

      // 依序排列  
      // 為了要往後插入
      while (currentPtr != NULL && value > currentPtr->data) { // 如果目前的指標不是空的，且輸入的數值大於目前的 data
         previousPtr = currentPtr; // 目前的變成舊的         
         currentPtr = currentPtr->nextPtr; // 新的變成目前的 
      }                                          

      // 如果舊的 node 地址是空的 
      // 就代表目前是在最前面
      // 也就是說我新的值（比較小）
      // 應該要插在這裡
      if (previousPtr == NULL) { 
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } 
      // 如果不是這種狀況，就代表我跑到中間或是尾巴
      // 那把前一個 node 的指標填入新的 node 的地址，
      // 新 node 的指標插入目前 node 的地址
      else { 
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr; // 注意，這裡插入的有可能是 NULL，代表我已經到尾巴ㄌ
      } 
   } 
   else {
      printf("%c not inserted. No memory available.\n", value); // 你的記憶體確診
   } 
} 

// 移除元素的程式
char delete(ListNodePtr *sPtr, char value)
{ 
   // 如果剛好找到的是第一個
   if (value == (*sPtr)->data) { 
      ListNodePtr tempPtr = *sPtr; // 把要刪除的 node 地址先暫時存起來
      *sPtr = (*sPtr)->nextPtr; // 複寫目前的地址為下一個 node 的地址
      free(tempPtr); // 把孤立的 node 給刪除
      return value; // 結束程式，把刪除的值給丟回去
   } 
   else {  // 不是的話，只好跑 loop
      ListNodePtr previousPtr = *sPtr; // 把目前的地址變成前一個 node
      ListNodePtr currentPtr = (*sPtr)->nextPtr; // 目前的地址變成下一個（？）

      // 找一下 node
      // 找到吻合的 node 為止
      while (currentPtr != NULL && currentPtr->data != value) { 
         previousPtr = currentPtr; // 遊走的時候，目前的變成前一個
         currentPtr = currentPtr->nextPtr; // 讀下一個 node 的地址
      } 

      // 找完了就開始砍
      // 因為吻合了，只要目前找到的 node 地址沒有怪怪的，就刪掉它
      if (currentPtr != NULL) { 
         ListNodePtr tempPtr = currentPtr; // 暫存要刪除的 node 地址
         previousPtr->nextPtr = currentPtr->nextPtr; // 把上一個的 node 的指標存放的地址，變成下下個 node 地址
         free(tempPtr); // 刪除被孤立的 node
         return value; // 回傳回去，結束這回和
      } 
   } 

   return '\0';
} 

// 檢查程式
// 比較一下是不是空的 （and 比較）
// 是就回傳 1 否則相反
int isEmpty(ListNodePtr sPtr)
{ 
   return sPtr == NULL; 
} 

// 印出來
void printList(ListNodePtr currentPtr)
{ 
   // 萬一是空的就直接告知使用者是空的
   if (isEmpty(currentPtr)) {
      puts("List is empty.\n");
   } 
   else {  // 不然就印出來
      puts("The list is:");

      // 不斷遊走把整個 link list 找完
      while (currentPtr != NULL) { 
         printf("%c --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;   
      } 

      puts("NULL\n"); // 最後一個一定是指向 NULL
   } 
} 


