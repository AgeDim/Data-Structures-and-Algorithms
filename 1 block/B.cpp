#include <iostream>
#include <stack>

using namespace std;

int main() {
    string row;
    cin >> row;
    int len = row.length();
    int counter = -1;
    for(int i = 0; i < len; i++) {
        if('a' <= row[i] && row[i] <= 'z' && row[i] - 'a' + 'A' == row[(i + 1) % len] || 'A' <= row[i] && row[i] <= 'Z' && row[i] - 'A' + 'a' == row[(i + 1) % len]){
            counter = i;
         break;
        }
    }
    if(counter == -1){
        cout << "Impossible" << endl;
        return 0;
    }
    string t;
    for(int i = counter; i < len; i++){
        t.push_back(row[i]);
    }
    for(int i = 0; i < counter; i++){
        t.push_back(row[i]);
    }
    stack<int> stack;
    int answer[len];
    for(int i =0; i < len; i++){
        if(stack.empty() || !('a' <= t[stack.top()] && t[stack.top()] <= 'z' && t[stack.top()] - 'a' + 'A' == t[i] || 'A'<= t[stack.top()] && t[stack.top()] <= 'Z' && t[stack.top()] - 'A' + 'a' == t[i])){
        stack.push(i);
        }else{
            answer[i] = stack.top();
            answer[stack.top()] = i;
            stack.pop();
        }
    }
    if(stack.empty()){
        cout << "Possible" << endl;

       int index[len];
        int j = 1;
        for(int i = 0; i < len; i++){
            if('a' <= row[i] && row[i] <= 'z'){
                index[(i - counter + len) % len] = j++;
            }
        }
        for(int i = 0; i < len; i++){
            if('A' <= row[i] && row[i] <= 'Z'){
                cout << index[answer[(i - counter + len) % len]] << ' ';
            }
        }
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}
