#ifndef DSU_H
#define DSU_H

#include <vector> 

using namespace std; 

class DSU{
    private: 
        vector<int> parent, rank; 
    
    public: 
        DSU(int n); 
        int find(int x); 
        bool unite(int x, int y); 

}; 
#endif