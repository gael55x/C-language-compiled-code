// adjacency matrix based implementation of prim's algorithm
#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <climits> 

using namespace std; 

vector<int> selected; 
vector<int> near; 
vector<vector<int>> cost; 

void initGraph(int n, int m){
    cost.assign(n, vector<int>(n, INT_MAX)); 
    selected.assign(n, 0); 
    near.assign(n, -1); 
}

int prims(int n){
    int u = -1, v = -1, EdgeMin = INT_MAX; 

    // find initial min edge 
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (cost[i][j] < EdgeMin){
                EdgeMin = cost[i][j]; 
                u = i; 
                v = j; 
            }
        }
    }

    // add min edge to mst 
    selected[u] = selected[v] = 1; 
    near[u] = near[v] = -1; 

    int total = cost[u][v]; 
    cout << "Edges in MST: " << u << " " << v  << "Weight: " << EdgeMin << endl; 

    // init near 
    for (int i = 0; i < n; i++){
        if (!selected[i]){
            if (cost[i][u] < cost[i][v]){
                near[i] = u; 
            } else {
                near[i] = v; 
            }
        }
    }

    // we repeat that for n - 2 times 
    for (int i = 1; i < n - 1; i++){
        int k = -1; 

        int minCost = INT_MAX; 
        for (int j = 0; j < n; j++){
            if (!selected[j] && cost[j][near[j]] < minCost){
                minCost = cost[j][near[j]]; 
                k = j; 
            }
        }
        if (k == -1) break; 
        cout << "Edges in MST: " << k << " " << near[k] << " " << "Weight: " << cost[k][near[k]] << endl; 
        total += cost[k][near[k]]; 
        selected[k] = 1; 
        near[k] = -1; 
        for (int j = 0; j < n; j++){
            if (!selected[j] && cost[j][near[j]] > cost[j][k]){
                near[j] = k; 
            }
        }
    }
    return total; 
}

int main(){
    int n, m; 
    cout << "Enter the number of vertices: "; 
    cin >> n >> m; 
    initGraph(n, m); 

    for (int i = 0; i < m; i++){
        int u, v, w; 
        cout << "Enter the edge and weight: "; 
        cin >> u >> v >> w; 
        u--; v--; 
        cost[u][v] = w; 
        cost[v][u] = w; 
    }

    int res = prims(n); 
    cout << "Total weight of MST: " << res << endl; 
}