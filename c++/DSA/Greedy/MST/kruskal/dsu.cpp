// DSU + path compression + union by rank 

#include "dsu.h"

// constructor - initialize parent and rank arrays 
DSU::DSU(int n){
    parent.resize(n); 
    rank.resize(n, 0); 

    for (int i = 0; i < n; i++) {
        parent[i]= i; 
    }
}

int DSU::find(int x){
    // path compression here 
    if (parent[x] != x) {
        parent[x] = find(parent[x]); 
    }
    return parent[x]; 
}

bool DSU::unite(int x, int y){
    int rootX = find(x); 
    int rootY = find(y); 

    if (rootX == rootY) return false; 

    // union by rank
    if (rank[rootX] < rank[rootY]){
        parent[rootX] = rootY; 
    }
    else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX; 
    } else {
        parent[rootY] = rootX; 
        rank[rootX]++; 
    }

    return true; 

}