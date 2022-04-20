#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int n, k;
    deque<int> value;
    deque<int> index;
    vector<int> res;
    vector<int> array;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int z;
        cin >> z;
        array.push_back(z);
    }
    for (int j = 0; j < n; j++) {
        while (!value.empty() && value.back() >= array[j]) {
            value.pop_back();
            index.pop_back();
        }
        value.push_back(array[j]);
        index.push_back(j);
        while (index.front() < j + 1 - k) {
            value.pop_front();
            index.pop_front();
        }
        if (j + 1 >= k) {
            res.push_back(value.front());
        }
    }
    for (int i: res) {
        cout << i << " ";
    }
    return 0;
}