/*
    Kruskal's algorithm for finding the minimum spanning tree of a graph 
    uses union by size and path compression 
    time complexity: O(m log m) - sorting edges + O(m alpha(n)) - DSU operations 
    space complexity: O(m + n) - edges + DSU arrays 
*/

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <iomanip> 

using namespace std; 

typedef struct Edge{
    int u, v, weight; 
} Edge; 

// let's use union by size and path compression
class DSU {
    private: 
        vector<int> parent; 

    public: 
        DSU(int n){
            parent.resize(n, -1); 
        }
        // path compression
        int find(int x){
            if (parent[x] < 0) return x; 
            return parent[x] = find(parent[x]); 
        }

        bool unite(int x, int y){
            int rootX = find(x); 
            int rootY = find(y); 
            if (rootX == rootY) return false; 

            if (size(rootX) < size(rootY)){
                swap(rootX, rootY); 
            }
            parent[rootX] += parent[rootY]; 
            parent[rootY] = rootX; 

            return true; 
        }

        int size(int x){
            return -parent[find(x)]; 
        }

}; 

int kruskal(int n, vector<Edge>& edges){
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.weight < b.weight; 
    }); 

    int mincost = 0; 
    DSU dsu(n); 
    vector<Edge> mst; 
    for (const Edge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)){
            mincost += edge.weight; 
            mst.push_back(edge); 
        }
    }
    cout << "Edges in the MST: " << endl; 
    for (const Edge& edge : mst){
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl; 
    }
    return mincost; 
}

int main(){
    int n, m; 

    cout << "Enter the number of vertices and edges: "; 
    cin >> n >> m; 

    vector<Edge> edges(m); 

    cout << "Enter the edges (u, v, weight): "; 
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight; 
    }


    int mincost = kruskal(n, edges); 
    cout << "Minimum cost of the MST: " << mincost << endl; 

    return 0; 
}