/* 
binary search 相關
需要先排序才可以用
*/

// 從這可以看出 print 和 binary search 本身如何使用
// enter key to binary search
    printf("%s", "Enter a number: ");
    int key;
    scanf("%d%*c", &key);
    

    printHeader(counter);
    size_t result = binarySearch(a, key, counter-1);
    if (result != -1) {
        printf("\n%d found at index %d\n", key, result);
    } 
    else {
        printf("\n%d not found\n", key);
    } 


size_t binarySearch(const int b[], int searchKey, size_t high)
{
   size_t low = 0;
   int counter = high + 1;
   // loop until low index is greater than high index
   while (low <= high) {

      // determine middle element of subarray being searched
      size_t middle = (low + high) / 2;

      // display subarray used in this loop iteration
      printRow(b, low, middle, high, counter);

      // if searchKey matched middle element, return middle
      if (searchKey == b[middle]) {                       
         return middle;                                       
      }                                           

      // if searchKey is less than middle element, set new high
      else if (searchKey < b[middle]) {                    
         high = middle - 1; // search low end of array      
      }                                     

      // if searchKey is greater than middle element, set new low
      else {                                                     
         low = middle + 1; // search high end of array        
      }                                            
   } // end while

   return -1; // searchKey not found
} 

// Print a header for the output
void printHeader(int counter)
{
   puts("\nSubscripts:");

   // output column head
   for (unsigned int i = 0; i < counter; ++i) {
      printf("%3u ", i);
   } 

   puts(""); // start new line of output

   // output line of - characters
   for (unsigned int i = 1; i <= 4 * counter; ++i) {
      printf("%s", "-");
   } 

   puts(""); // start new line of output
} 

// Print one row of output showing the current
// part of the array being processed.
void printRow(const int b[], size_t low, size_t mid, size_t high, int counter)
{
   // loop through entire array
   for (size_t i = 0; i < counter; ++i) {

      // display spaces if outside current subarray range
      if (i < low || i > high) {
         printf("%s", "    ");
      }  
      else if (i == mid) { // display middle element
         printf("%3d*", b[i]); // mark middle value
      } 
      else { // display other elements in subarray
         printf("%3d ", b[i]);
      } 
   }
   
   puts(""); // start new line of output
} 
