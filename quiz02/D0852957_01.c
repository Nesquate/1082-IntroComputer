#include <stdio.h>

struct fraction
{
int numerator; // mon
int denominator; //son
};

typedef struct fraction frac;

struct fraction sub(struct fraction a, struct fraction b);
void fracEnter(frac *Ptr, frac *Ptr2);
int gcd(int m, int n);

int main(){
    frac dataA, dataB;
    fracEnter(&dataA, &dataB);
    sub(dataA, dataB);

    return 0;
}

void fracEnter(frac *Ptr, frac *Ptr2){
    printf("Please enter the first fraction(numberator first, then denominator): \n");
    scanf("%d %d", &Ptr->numerator, &Ptr->denominator);
    getchar();
    

    printf("Please enter the second fraction(numberator first, then denominator): \n");
    scanf("%d %d", &Ptr2->numerator, &Ptr2->denominator);
    getchar();
}

struct fraction sub(struct fraction a, struct fraction b){
    int mol,r;

    if(a.denominator != b.denominator){
        a.numerator *=  b.denominator;
        b.numerator *= a.denominator;
        a.denominator *= b.denominator;
        b.denominator = a.denominator;
    }

    mol = a.numerator -  b.numerator;
    r = gcd(mol,a.denominator);
    mol /= r;
    a.denominator  /= r;

    printf("Fraction : \n");
    if(mol > a.denominator && (mol % a.denominator ) != 0){
        printf("%d(%d/%d)\n", 
        mol / a.denominator ,
        mol - a.denominator ,
        a.denominator );
    }
    else if(mol == a.denominator || (mol % a.denominator == 0)){
        printf("%d\n", mol / a.denominator );
    }
    else{
        printf("(%d/%d)\n",
        mol,
        a.denominator );
    }
}

int gcd(int m, int n) {
    while(n != 0) { 
        int r = m % n; 
        m = n; 
        n = r; 
    } 
    return m;
}

