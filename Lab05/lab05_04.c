#include<stdio.h>

struct fraction{
    int den; // mon
    int mol; // son
    int dec; // integer
};

typedef struct fraction frac;

void fracEnter(frac *Ptr);
void fracAdder(frac *Ptr);
int gcd(int m, int n);

int main(){
    frac data[2];

    fracEnter(data);
    fracAdder(data);

    return 0;
}

void fracEnter(frac *Ptr){
    printf("Enter fraction 1 (x/y) : ");
    scanf("%d/%d", &Ptr->mol, &Ptr->den);
    getchar();
    
    Ptr++;

    printf("Enter fraction 2 (x/y) : ");
    scanf("%d/%d", &Ptr->mol, &Ptr->den);
    getchar();
}

void fracAdder(frac *Ptr){
    int mol,r;

    if(Ptr->den != (Ptr+1)->den){
        Ptr->mol *= (Ptr + 1)->den;
        (Ptr + 1)->mol *= (Ptr)->den;
        Ptr->den *= (Ptr + 1)->den;
        (Ptr + 1)->den = Ptr->den;
    }

    // printf("%d\n%d\n", Ptr->mol, (Ptr + 1)->mol);

    mol = Ptr->mol + (Ptr + 1)->mol;
    r = gcd(mol,Ptr->den);
    mol /= r;
    Ptr->den /= r;

    printf("Fraction : \n");
    if(mol > Ptr->den && (mol % Ptr->den) != 0){
        printf("%d(%d/%d)\n", 
        mol / Ptr->den,
        mol - Ptr->den,
        Ptr->den);
    }
    else if(mol == Ptr->den || (mol % Ptr->den == 0)){
        printf("%d\n", mol / Ptr->den);
    }
    else{
        printf("(%d/%d)\n",
        mol,
        Ptr->den);
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
