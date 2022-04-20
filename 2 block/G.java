#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    string first;
    string res;
    cin >> first;
    string second;
    map<char, int> line2;
    map<char, int> counter;
    vector<string> size;
    vector<char> tmp;
    vector<char> result;

    for (char i = 'a'; i <= 'z'; ++i) {
        cin >> second;
        line2[i] = atoi(second.c_str());

    }

    for (char &i: first) {
        if ((find(tmp.begin(), tmp.end(), i) == tmp.end())) {
            tmp.push_back(i);
        }


    }

    for (int i = 0; i < tmp.size() - 1; ++i) {
        for (int j = i + 1; j < tmp.size(); ++j) {
            if (line2[tmp[i]] > line2[tmp[j]]) {
                swap(tmp[i], tmp[j]);
            }
        }
    }

    for (char &i: first) {
        counter[i] = counter[i] + 1;
    }

    for (char &i: tmp) {
        if (counter[i] == 1) {
            res += i;
        }
        if (counter[i] == 2) {
            result.push_back(i);

        }

        if (counter[i] > 2) {
            result.push_back(i);
            for (int j = 0; j < counter[i] - 2; ++j) {
                res += i;
            }

        }
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[result.size() - 1 - i];
    }
    cout << res;

    for (char i: result) {
        cout << i;
    }
    return 0;
}