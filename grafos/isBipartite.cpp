#include<bits/stdc++.h>

using namespace std;

bool isBipartite(const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> color(n, -1); 
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) { 
            queue<int> q;
            q.push(i);
            color[i] = 0; 

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) { 
                        color[v] = 1 - color[u]; 
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; 
                    }
                }
            }
        }
    }

    return true; 
}
