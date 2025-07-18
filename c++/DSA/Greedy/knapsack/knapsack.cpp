// knapsack problem
// todo: need to be fractional knapsack

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 

using namespace std;

typedef struct Item {
    int weight; 
    int value; 
    float ratio; 

    Item(int w, int v): weight(w), value(v) {
        ratio = static_cast<float>(v) / w; 
    }
} Item; 

int main() {
    vector<Item> items; 

    cout << "Enter weights and values (-1 to stop):\n";
    int weight, value; 
    while (cin >> weight >> value) {
      if (weight == -1) break; 
      items.emplace_back(weight, value); 
    }


    int maxW = 50;

    sort(items.begin(), items.end(), [](const Item& a, const Item& b){
        return a.ratio > b.ratio; 
    }); 

    double res = 0.0; 
    for (auto& item : items){
        if (maxW >= item.weight){
            res += item.value; 
            maxW -= item.weight; 
        } else {
            res += maxW * item.ratio; 
            break; 
        }
    }
    cout << "Maximum profit: "; 
    cout << fixed << setprecision(2) << res << endl; 
    return 0; 
}

