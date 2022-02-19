#include <iostream>
using namespace std;

int digits(long long N){
int count = 0;
    while (N){
        ++count;
        N /= 10;
    }
 return count;
}

int solve(long long N){

    int res = 1000, d = digits(N);

    for (int s = 1; s <= (1 << d); ++s){
        int removed = 0, mask = s;
        auto M = N, X = 0LL, base = 1LL;
        while (M){

            if (mask & 1){
                X += (base * (M % 10));
                base *= 10;
            } else
                ++removed;
                M /= 10;
                mask >>= 1;
        }
        //cout << X << '\n';
        //cout << "resto = " << X % 3 << ", removed = " << removed << ", d = " << d << "\n";
    if (X % 3 == 0 and removed < d)
        res = min(res, removed);

    }
 return res == 1000 ? -1 : res;
}


int main(){
    long long N;
    cin >> N;
    auto res = solve(N);
    cout << res << '\n';
    return 0;
}
