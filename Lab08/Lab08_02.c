#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000

void insertionSort( int array[], int length );
size_t binarySearch(const int b[], int searchKey,size_t high);
void printHeader(int counter);
void printRow(const int b[], size_t low, size_t mid, size_t high, int counter);

int main(){
    FILE *fptrRead, *fptrCreate;
    int counter = 0, counterWrite = 0;
    int array[SIZE],a[SIZE]; 

    // Sort number and save to Sorted_data.txt
    if ( (fptrRead = fopen("data.txt","r"))  == NULL || (fptrCreate = fopen("Sorted_data.txt", "w"))== NULL){
        printf("Can not open file.\n");
    }
    else{
        while(1){
            fscanf(fptrRead,"%d%*[^ ]",&array[counter]);
            if(feof(fptrRead)){
                fclose(fptrRead);
                break;
            }
            counter++;
        }

        insertionSort(array,counter+1);

        while(counterWrite <= counter){
            fprintf(fptrCreate, "%d ", array[counterWrite]);
            counterWrite++;
        }
        fclose(fptrCreate);
        counter = 0;
        counterWrite = 0;
    }

    // Read sorted from Sorted_data.txt 
    if ( (fptrRead = fopen("Sorted_data.txt","r"))  ==  NULL  ){
         printf("Can not open file.\n");
    }
    else{
        while(1){
            fscanf(fptrRead,"%d%*[^ ]",&a[counter]);
            if(feof(fptrRead)){
                fclose(fptrRead);
                break;
            }
            counter++;
        }

        // random array number to binary search
        printHeader(counter);
        srand(time(NULL));
        int random = (rand() % (counter - 1));
        size_t result_random = binarySearch(a, a[random], counter-1);
        if (result_random != -1) {
            printf("\n%d found at index %d\n", a[random], result_random);
        } 
        else {
            printf("\n%d not found\n", a[random]);
        } 

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
    }

   return 0;
}

void insertionSort( int array[], int length )
{
   int insert; /* temporary variable to hold element to insert */
   int i; /* int used in for loop */
    
   /* loop over length - 1 elements */
   for ( i = 1; i < length; i++ ) {
       int moveItem = i; /* initialize location to place element */
       insert = array[ i ];
        
       /* search for place to put current element */
       while ( moveItem > 0 && array[ moveItem - 1 ] > insert ) {
           /* shift element right one slot */
           array[ moveItem ] = array[ moveItem - 1 ];
           --moveItem;
       } /* end while */
        
       array[ moveItem ] = insert; /* place inserted element */
   } /* end for */
} /* end function insertionSort */

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

