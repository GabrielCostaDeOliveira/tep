template<typename T> 
struct SIMPLE_UFDS{
  std::vector<T> ps;
  SIMPLE_UFDS(T n):ps(n){
    iota(ps.begin(), ps.end(), 0);
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

    if (p == q)
      return;

    ps[q] = p;
  }


};
