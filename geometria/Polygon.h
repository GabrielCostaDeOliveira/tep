#include <bits/stdc++.h>
#include "util.h"


using namespace std;


template< typename T>
class Poligon{
    private:
        vector<int> vs;
        int n;

    public:
        Poligon( const vector<Point<T>> ps ) : vs(ps), n(ps.size()) {
            vs.push_back(vs.front());
        }


};


