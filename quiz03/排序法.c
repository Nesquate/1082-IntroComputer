/*
注意 這裡的 length 與 size
如果是使用陣列的 offset 數字做計算的話
記得 + 1
*/

// 泡沫
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

// 泡沫排序的交換
void swap(int *element1Ptr, int *element2Ptr)            
{                                                          
   int hold = *element1Ptr;                                
   *element1Ptr = *element2Ptr;                            
   *element2Ptr = hold;                                    
}

// 除了泡沫之外的印出
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


// 印出 bubble pass 多少次
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


// 選擇
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

// 選擇排序內的交換
/* function that swaps two elements in the array */
void swap_selection( int array[], int first, int second )
{
   int temp; /* temporary integer */
   temp = array[ first ];
   array[ first ] = array[ second ];
   array[ second ] = temp;
} /* end function swap */


// 插入
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



