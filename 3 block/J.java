#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    list<int> left;
    list<int> right;

    cin >> n;
    for (int i = 0; i < n; i++) {
        char str;
        cin >> str;
        int value;
        if (str == '+') {
            cin >> value;
            right.push_back(value);
            if (left.size() < right.size()) {
                left.push_back(right.front());
                right.pop_front();
            }
        } else {
            if (str == '*') {
                cin >> value;
                if (left.size() == right.size()) {
                    left.push_back(value);
                } else {
                    right.push_back(value);
                }
            } else {
                int res = left.front();
                left.pop_front();
                if (left.size() < right.size()) {
                    left.push_back(right.front());
                    right.pop_front();
                }
                cout << res << endl;
            }
        }
    }
}