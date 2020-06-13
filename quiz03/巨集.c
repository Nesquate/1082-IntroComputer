// 巨集

// 比較
#define COMPARE(X,Y) (\
    {\
       int C;\
       if (X > Y){\
           C =  X;\
        }\
        else if (X < Y){\
            C = Y;\
        }\
        else{\
            C = -1;\
        }\
        C;\
    }\
)

// 總和
#define SUM(x,y)(\
    {\
    int TOTAL;\
    TOTAL = x + y;\
    TOTAL;\
    }\
)

// 預先定義
    printf("__LINE__ : %d\n", __LINE__);
    printf("__FILE__ : %s\n", __FILE__);
    printf("__DATE__ : %s\n", __DATE__);
    printf("__TIME__ : %s\n", __TIME__);

// 字串
#define PRINT(STRING)(\
    {\
        printf(#STRING "\n" );\
    }\
)


