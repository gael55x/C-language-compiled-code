// Dijkstra's Algorithm (not optimized)
// using selected and distance array 
// time complexity: O(n^2)
// space complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> selected;
vector<int> dist;

vector<int> dijkstras(vector<vector<int>>& cost, int n, int s){
    dist[s] = 0; 

    for (int k = 1; k < n; k++){
        // get da min distance
        int min = INT_MAX, u = 0; 
        for (int i = 1; i <= n; i++){
            if (!selected[i] && dist[i] < min){
                u = i; 
                min = dist[i]; 
            }
        }
        if (u == -1) break; 
        // mark this vertex as true; 
        selected[u] = true; 
        // perform relaxation technique with the nearest vertices
        for (int v = 1; v <= n; v++){
            if (!selected[v] && cost[u][v] != INT_MAX && (dist[u] + cost[u][v])< dist[v]){
                dist[v] = dist[u] + cost[u][v]; 
            }
        }
    }
    return dist; 
}

int main(){
    int n, m; 
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m; 

    selected.assign(n + 1, 0); 
    dist.assign(n + 1, INT_MAX); 
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, INT_MAX)); 

    cout << "Enter the edges in the format (u v w): " << endl; 
    for (int i = 0; i < m; i++){
        int u, v, w; 
        cin >> u >> v >> w; 
        cost[u][v] = w; 
    }

    int src; 
    cout << "Enter source vertex: "; 
    cin >> src; 

    vector<int> res = dijkstras(cost, n, src); 

    cout << "Minimum single source path using Dijkstra's: " << endl; 
    for (int i = 1; i < res.size(); i++){
        cout << res[i] << endl; 
    }

    return 0; 
    
}


