
#include <bits/stdc++.h>

template<typename t>
size_t lis(std::vector<t> v ){

  std::set<t> s;


  for ( auto e : v){


    auto it = s.lower_bound(e);


    if ( it == s.end())
      s.insert(e);
    else{
      s.erase(it);

      s.insert(e);
    }

  }



  return s.size();
}
