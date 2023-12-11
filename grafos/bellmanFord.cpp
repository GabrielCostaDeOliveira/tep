#include <bits/stdc++.h>


// cominho mínimos de fonte únicas
// É capaz de processar arestas negativas
// identifica ciclos negativos
// O(V*E)

std::vector<int> bellmanfor(int s/*start*/, int N /*n de vertice*/, const std::vector<std::tuple<int, int, int>> & edges /*lista de arestas*/ ){
	const int oo {1000000010};

  std::vector<int> dist(N + 1, oo);
	dist[s] = 0;

	for (int i = 1; i <= N - 1; i++)
		for (auto [u, v, w] : edges)
			if (dist[u] < oo and dist[v] > dist[u] + w )
				dist[v] = dist[u] +w; // relaxamanro 

	return dist;
}

