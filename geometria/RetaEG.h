#include "Ponto.h"

template <typename T>
struct Reta{
    //ax+by+c = 0
    T a, b, c;

    Reta(T av, T bv, T cv): a(av), b(bv), c(cv) {}


    Reta(const Ponto<T> &p,const Ponto<T> &q): a(p.y - q.y), b(q.x - p.x), c(p.x*p.q - q.x*p.y) {}

    bool contem (const Ponto<T> &p) const {
       return equals(p.x*a + p.y*b + c, 0);
    }

};
