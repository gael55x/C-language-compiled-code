// knapsack problem
// todo: need to be fractional knapsack

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> weights;
    vector<int> values; 

    cout << "Enter weights (-1 to stop):\n";
    int input; 
    while (cin >> input) {
        if (input == -1) break;
        weights.push_back(input);
    }

    // Input values
    cout << "Enter values (-1 to stop):\n";
    input = 0; 
    while (cin >> input) {
        if (input == -1) break;
        values.push_back(input);
    }

    if (weights.size() != values.size()) {
        cerr << "Error: Number of weights and values must match.\n";
        return 1;
    }

    int maxW = 50;
    int n = weights.size();

    vector<pair<float, int> > ratio(n);
    for (int i = 0; i < n; i++) {
        ratio[i] = make_pair(static_cast<float>(values[i]) / weights[i], i);
    }

    sort(ratio.begin(), ratio.end(), [](const pair<float, int>& a, const pair<float, int>& b) {
        return a.first > b.first;
    });
    

    int res = 0; 
    for (int i = 0; i < n; i++) {
        if (maxW >= weights[ratio[i].second]) {
            res += values[ratio[i].second];
            maxW -= weights[ratio[i].second];
        } else {
            res += maxW * ratio[i].first;
            break;
        }
    }
    cout << res << endl; 
    return 0; 
}

