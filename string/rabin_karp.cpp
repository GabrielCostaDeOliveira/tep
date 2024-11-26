
#include<bits/stdc++.h>

#include"../MD/mint.cpp"

using namespace std;


int conv(char a){

  return a - 'a' + 1;

}


vector<mint> make_hash(const string& s, int N){

  vector<mint> hash(s.size());

  hash[0] = conv(s[0]);
  

  mint p(N);

  for (int i = 1 ;i <(int) s.size(); i++ ){
    hash[i] = mint(hash[i-1] + mint(conv(s[i])) * p.exp(i));
  }



  return hash;
}





int ranbin_karp(const string&s, const string&t, int N = 83) {



  int res = 0;

  mint hash_t = make_hash(t, N).back();

  vector<mint> hash_s = make_hash(s, N);


  int T = t.size();


  mint p = N;

  auto query = [&](int i, int j) -> mint{
    return (hash_s[j] - (i - 1 >= 0 ? hash_s[i - 1] : 0) );
  };

  for ( int j = T - 1; j < (int) s.size(); j++ ) {

    int i = j - T + 1;

    if ( (query(i , j)) * p.exp(i).inv() == hash_t)
      res++;


   /*cout << "SUB( " << i <<", "<< j<<") = " << (query(i, j)) <<  " "<< (query(i , j)) * p.exp(i).inv() << endl;*/


  }



  return res;

}
 
