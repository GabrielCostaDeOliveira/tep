#include "Ponto.h"

template<typename T>
struct Circle{
    Point<T> C;
    T r;

    double arc(double theta);
    bool isin (Circle C);
};

//a unidade de theta é radianos
template<typename T>
double Circle<T>::arc(double theta){
    return theta * r;
}

//confere se o circulo contém outro
template<typename T>
bool Circle<T>::isin(Circle A){
    return  r <= C.distTo(A.C) + A.r;
}


