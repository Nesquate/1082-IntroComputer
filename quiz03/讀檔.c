    
    FILE *fptr; // 讀檔指標

    if ( (fptr = fopen("data.txt","r"))  == NULL ){
        printf("Can not open file.\n");
    }
    else{
        while(1){ // 防止多讀一次的寫法
            fscanf(fptr,"%d%*[^ ]",&array[counter]); // 這是一個一個數字讀來的大致寫法，數字放到 array 去
            if(feof(fptr)){
                fclose(fptr);
                break;
            }
            counter++;
        }

        // 這是為了多個排序操作使用的
        // 因為排序之後原陣列會變動
        // 所以就用三個陣列分別處理三個排序法
        puts("Data items in original order"); 
        // loop through array
        for (size_t i = 0; i <= counter; ++i) {
            array2[i] = array[i];
            array3[i] = array[i];
            printf("%4d", array[i]);
        }

        // 按 ENTER 繼續 （使用者操作相關）
        printf("Press [ENTER] to continue ...");
        getchar();

    }