#include <bits/stdc++.h>

using namespace std;

void imprime(int C){
    for (int i = 0; i <32; i++)
        if (C & (1 << i))
            cout << i << " ";
    cout << endl;
}

int main(){
    //conjuntos com inteitos
    int A {32915}, // {0, 1, 4, 7, 15}
        B {159}, // {0, 1 ,2 ,3, 4, 7}
        C;

    cout << "A = ";
    imprime(A);

    cout << "B = ";
    imprime(B);

    //uniãp
    C = A | B;
    imprime(C);

    //intesseção
    C = A & B;
    imprime(C);

    //diferença
    //A-B
    C = A & ~B;
    imprime(C);

    //B - A
    C = B & ~A;
    imprime(C);
    

}
