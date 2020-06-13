#include<stdio.h>
#define SIZE 1000

void bubbleSort(int array[], const size_t size); 
void insertionSort( int array[], int length );
void selectionSort( int array[], int length );
void swap_selection( int array[], int first, int second );

void printPass( int array[], int length, int pass, int index );
void printPassBubble( int array[], int length, int pass, int index );

int main(){
    FILE *fptr;
    int array[1000],array2[1000],array3[1000];;
    int counter = 0;

    if ( (fptr = fopen("data.txt","r"))  == NULL ){
        printf("Can not open file.\n");
    }
    else{
        while(1){
            fscanf(fptr,"%d%*[^ ]",&array[counter]);
            if(feof(fptr)){
                fclose(fptr);
                break;
            }
            counter++;
        }

        puts("Data items in original order");
        // loop through array
        for (size_t i = 0; i <= counter; ++i) {
            array2[i] = array[i];
            array3[i] = array[i];
            printf("%4d", array[i]);
        }
        printf("\n");

        printf("\nBubble sort :\n");
        bubbleSort(array, counter+1);
        printf("Press [ENTER] to continue ...");
        getchar();

        printf("\nInsertion sort :\n");
        insertionSort(array3,counter+1);
        printf("Press [ENTER] to continue ...");
        getchar();
        
        printf("\nSelection sort :\n");
        selectionSort(array2,counter+1);
        printf("Press [ENTER] to continue ...");
        getchar();

        return 0;

    }

}

// sort an array of integers using bubble sort algorithm
void bubbleSort(int array[], const size_t size)
{
   int counter = 1;
   void swap(int *element1Ptr, int *element2Ptr); // prototype
   
   // loop to control passes
   for (unsigned int pass = 0; pass < size - 1; ++pass) {

      // loop to control comparisons during each pass
      for (size_t j = 0; j < size - 1; ++j) {

         // swap adjacent elements if they're out of order
         if (array[j] > array[j + 1]) {
            swap(&array[j], &array[j + 1]);
            printPassBubble( array, size ,counter, j); 
            counter++;
         }
      }
      
   }

}

/* function that selection sorts the array */
void selectionSort( int array[], int length )
{
   int smallest; /* index of smallest element */
   int i, j; /* ints used in for loops */
    
   /* loop over length - 1 elements */
   for ( i = 0; i < length - 1; i++ ) {
      smallest = i; /* first index of remaining array */
        
       /* loop to find index of smallest element */
       for ( j = i + 1; j < length; j++ )
          if ( array[ j ] < array[ smallest ] )
             smallest = j;
                
       swap_selection( array, i, smallest ); /* swap smallest element */
       printPass( array, length, i + 1, smallest ); /* output pass */
   } /* end for */
} /* end function selectionSort */

/* function that sorts the array */
void insertionSort( int array[], int length )
{
   int insert; /* temporary variable to hold element to insert */
   int i; /* int used in for loop */
   int counter = 1;
    
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
      //  printf("Debug : moveItem = %d\n", moveItem);
      //  printf("Debug : i = %d\n", i);
      //  printf("Debug : insert = %d\n", insert);
      //  printf("Debug : array[ moveItem ] = %d\n", array[moveItem]);
      //  printf("Debug : array[ moveItem - 1 ] = %d\n", array[moveItem - 1]);
      //  getchar();
       if ( array[ moveItem ] != insert ){
          array[ moveItem ] = insert; /* place inserted element */
          printPass( array, length, counter, moveItem );
          counter++;
       }
      
       
   } /* end for */
} /* end function insertionSort */

/* function that swaps two elements in the array */
void swap_selection( int array[], int first, int second )
{
   int temp; /* temporary integer */
   temp = array[ first ];
   array[ first ] = array[ second ];
   array[ second ] = temp;
} /* end function swap */

void swap(int *element1Ptr, int *element2Ptr)            
{                                                          
   int hold = *element1Ptr;                                
   *element1Ptr = *element2Ptr;                            
   *element2Ptr = hold;                                    
}

/* function that prints a pass of the algorithm */
void printPass( int array[], int length, int pass, int index )
{
   int i; /* int used in for loop */
    
   printf( "After pass %2d: ", pass );
    
   /* output elements till selected item */
   for ( i = 0; i < index; i++ )
      printf( "%d  ", array[ i ] );
        
   printf( "%d* ", array[ index ] ); /* indicate swap */
    
   /* finish outputting array */
   for ( i = index + 1; i < length; i++ )
      printf( "%d  ", array[ i ] );
        
   printf( "%s", "\n               " ); /* for alignment */
    
   /* indicate amount of array that is sorted */
    
   puts( "\n" ); /* add newline */
} /* end function printPass */

void printPassBubble( int array[], int length, int pass, int index )
{
   int i; /* int used in for loop */
    
   printf( "After pass %2d: ", pass );
    
   /* output elements till selected item */
   for ( i = 0; i < index; i++ )
      printf( "%d  ", array[ i ] );
        
   printf( "%d* ", array[ index ] ); /* indicate swap */
    
   /* finish outputting array */
   for ( i = index + 1; i < length; i++ )
      printf( "%d  ", array[ i ] );
        
   printf( "%s", "\n               " ); /* for alignment */
    
   /* indicate amount of array that is sorted */

    
   puts( "\n" ); /* add newline */
} /* end function printPass */


