#include <numeric>
#include <vector>
template<typename T> 
struct UFDS{
  std::vector<T> ps;
  UFDS(T n):ps(n){
    std::iota(ps.begin(), ps.end(), 0);
  }


  T find_set(T x){
    return x == ps[x] ? x : ps[x] = find_set(ps[x]);
  }

  bool same_set(T a, T b){
    return find_set(a) == find_set(b);
  }



  void union_set(T a, T b){
    T p = find_set(a);
    T q = find_set(b);

    ps[q] = p;
  }


};
