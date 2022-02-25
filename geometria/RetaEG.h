#include "Ponto.h"
#include <utility>

const int INF {-1};

template <typename T>
struct Line{
    //ax+by+c=0
    T a, b, c;

    Line(T av, T bv, T cv): a(av), b(bv), c(cv) {}


    Line(const Ponto<T> &p,const Ponto<T> &q): a(p.y - q.y), b(q.x - p.x), c(p.x*p.q - q.x*p.y) {}

    bool contem (const Ponto<T> &p) const {
       return equals(p.x*a + p.y*b + c, 0);
    }

    bool operator==(const Line& r) const{
        auto k = a ? a : b;
        auto s = r.a ? r.a : r.b;

        return equals(a*s, r.a*k) && equals(b*s, r.b*k) && equals(c*s, r.c*k);
    }

    bool parallel(const Line& r) const{
        auto det = a*r.b - b*r.a;

        //ele é parallel se o determindadno for 0 e ele não forem iguais
        //se o determinate for diferente de 0 elas são concorentes
        return det == 0 and (*this == r);
    }

    bool orthogonal(const Line& r) const {
        return equals(a * r.a + b*r.b + c*r.c, 0);
    }

    std::pair <int, Ponto<T>> intersection(const Line<T>& r){
        auto det = a*r.b - b*r.a;

        if (equals(det, 0))  //coincidentes ou paralelas
            return {(*this) == r ? INF : 0, {}};
        else {
            auto x = (-r.c + r.c*b)/det;
            auto y = (-a*r.c + r.a*c)/det;

            return {1, {x, y}};
        }
    }


    static double angle (const Ponto<T> &p,const Ponto<T> &q,const Ponto<T> &r,const Ponto<T> &s){
        auto ux = p.x - q.x;
        auto uy = p.y - q.y;

        auto vx = r.x - s.x;
        auto vy = r.y - s.y;

        auto num = ux*vx + uy*vy;
        auto den = hypot(ux, uy) + hypot(vx, vy);

        return acos(num/den);
    }

};

