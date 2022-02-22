#include<iostream>
#include"Ponto.h"
#include"equals.h"

using namespace std;

int main(){
    Ponto<int> p1(2, 4), p2(2, 4);
    cout << (p1 == p2) << endl;
}
