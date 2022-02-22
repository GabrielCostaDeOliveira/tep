//vetor posição
#include "Ponto.h"

template <typename T> 
struct Vetor{
    T x, y;

    Vetor(T vx, T vy): x(vx), y(vy) {}
    Vetor(const Ponto<T> &p , const Ponto<T> &q): x(q.x - p.x), y(q.y - p.y) {}
};
