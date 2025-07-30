// optimal k-way merge pattern with multiple lists using priority queue
#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

int Optimalmerge(vector<int> sizes){
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq(sizes.begin(), sizes.end()); 
    // if max heap then it would be priority_queue<int> pq(sizes.begin(), sizes.end()); 
    int res = 0; 
    while (pq.size() > 1){
        int a = pq.top(); pq.pop(); 
        int b = pq.top(); pq.pop(); 

        res += a + b; 
        pq.push(res); 
    }
    return res; 
}

int main(){
    vector<vector<int>> lists = {
        {1,2,3,4,5,6,7,8},
        {9,10,11,12,13,14,15},
        {16,17,18,19,20,21},
        {22,23,24,25,26,27,29},
        {30,31,32,33,34,35,36,37}
    }; 

    // optimal k-way merging with minimum cost;     
    vector<int> sizes; 
    for (auto &list : lists){
        sizes.push_back(list.size()); 
    }

    int cost = Optimalmerge(sizes); 

    cout << "Optimal total min cost: " << cost << endl; 
}