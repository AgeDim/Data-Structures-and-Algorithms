#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n = 0, k = 0, p = 0, val = 0, maxes = 0, num = 0, max = 500000;
    cin >> n;
    cin >> k;
    cin >> p;
    map<int, int, greater<>> heap;
    vector<vector<int>> coef;
    bool flag[n] = {false};
    int req[p];
    for (int i = 0; i < p; i++) {
        cin >> req[i];
    }
    int index[n] = {0};

    coef.resize(n);
    for (int i = 0; i < p; i++) {
        coef[req[i] - 1].push_back(i);
    }
    for (size_t i = 0; i < p; i++) {
        if (!flag[req[i] - 1]) {
            if (heap.size() >= k) {
                val = (*heap.begin()).first;
                maxes = (*heap.begin()).second;
                heap.erase(val);
                flag[maxes - 1] = false;
            }
            num++;
            flag[req[i] - 1] = true;
        } else {
            heap.erase(coef[req[i] - 1][index[req[i] - 1]]);
        }
        index[req[i] - 1] = index[req[i] - 1] + 1;
        if (index[req[i] - 1] >= coef[req[i] - 1].size()) {
            heap[max + 1] = req[i];
        } else {
            heap[coef[req[i] - 1][index[req[i] - 1]]] = req[i];
        }
    }
    cout << num;
}