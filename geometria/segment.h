#include "RetaEG.h"
#include "equals.h"

template<typename T>
struct segment{
    Ponto<T> A,B;

    bool contains(const Ponto<T> &P) const;
    Ponto<T> closest(const Ponto<T> &p) const;


};

template<typename T>
bool segment<T>::contains(const Ponto<T> &P) const {
        //verifica se P está contido na reta 
        double dAB = Ponto<T>::dist(A, B),
               dAP = Ponto<T>::dist(A, P),
               dPB = Ponto<T>::dist(P, B);

        return equals(dAP + dPB, dAB);
}

template<typename T>
Ponto<T> segment<T>::closest(const Ponto<T> &P) const {
    Line<T> R(A, B);
    auto Q = R.closest(P);

    if (this->contains(Q))
        return Q;

    auto distA = Ponto<T>::dist(P, A);
    auto distB = Ponto<T>::dist(P, B);

    if (distA <= distB)
        return A;
    else 
        return B;

}


