#include <stdio.h>
int main ()
{
    enum seasons {spring, summer, fall, winter};
    typedef enum seasons SEASON;
    SEASON s;
for ( s = spring; s <= winter; s++){
        switch (s){
            case spring: printf("春桃\n");
            break;
            case summer: printf("夏荷\n");
            break;
            case fall: printf("秋菊\n");
            break;
            case winter: printf("冬梅\n");
            break;
            default: break;
        }
    }
}