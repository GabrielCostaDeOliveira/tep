#include <type_traits>
#include <cmath>

const double EPS {1e-9};

template<typename T>
bool equals(T a, T b){
    if(std::is_floating_point<T>::value)
        return fabs(a-b) < EPS;
    else 
        return a == b;

}
