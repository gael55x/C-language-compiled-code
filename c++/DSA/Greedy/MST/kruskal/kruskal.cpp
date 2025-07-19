// Kruskal's algorithm for finding the minimum spanning tree of a graph 
// uses DSU to check if adding an edge creates a cycle 
// uses greedy approach to add the smallest edge that doesnt create a cycle 
// time complexity: O(m log m) - sorting edges + O(m alpha(n)) - DSU operations 
// space complexity: O(m + n) - edges + DSU arrays 

// g++ -std=c++17 kruskal.cpp dsu.cpp -o kruskal 

#include <iostream> 
#include <vector> 
#include "dsu.h"
#include <algorithm> 

using namespace std; 

typedef struct Edge{
    int u, v, weight; 
} Edge; 


int main(){
    int n, m; 
    cout << "Enter the number of vertices and edges: "; 
    cin >> n >> m; 

    vector<Edge> edges(m); 
    cout << "Enter the edges (u, v, weight): "; 
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight; 
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.weight < b.weight; 
    }); 

    DSU dsu(n); 
    vector<Edge> mst; 
    int mstWeight = 0; 

    for (const Edge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge); 
            mstWeight += edge.weight; 
        }
    }

    cout << "MINIMUM SPANNING TREE WEIGHT: " << mstWeight << endl; 
    cout << "EDGES IN MST: " << endl; 
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl; 
    }

    return 0; 
}