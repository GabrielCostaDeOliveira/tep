#include <type_traits>
#include <cmath>
#include "Point.h"

const double EPS {1e-9};

template<typename T>
bool equals(T a, T b){
    if(std::is_floating_point<T>::value)
        return fabs(a-b) < EPS;
    else 
        return a == b;

}

template<typename T>
T D(const Point<T> &P, const Point<T> &Q, const Point<T> &R){
    return (P.x*Q.y + P.y*R.x + Q.x*R.y) - (R.x*Q.y + R.y* P.x + Q.x*P.y);
}
