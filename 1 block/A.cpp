#include <iostream>
#include <vector>

using namespace std;
 
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto& it : a)
        cin >> it;
    if (n <= 3) {
        if (n == 3 && a[0] == a[1] && a[1] == a[2]) {
            cout<<"1 2";
        }
        else if (n == 3) {
            cout<<"1 3";
        }
        else if (n == 2) {
            cout<<"1 2";
        }
        else {
            cout<<"1 1";
        }
        return 0;
    }
    int maxLenght = 2;
    int start = 0;
    int end = 1;
    int lenght = 1;
    int indStart = 0;
    int count = 0;
    for (int indEnd = 1; indEnd < n; ++indEnd) {
        if (a[indEnd] == a[indEnd - 1]) {
            count++;
        }
        else {
            count = 0;
        }
        if (count + 1 == 3) {
            if (maxLenght < lenght) {
                maxLenght = lenght;
                start = indStart;
                end = indEnd - 1;
            }
            count = 1;
            lenght = 2;
            indStart = indEnd - 1;
        }
        else {
            if (maxLenght < lenght) {
 
            }
            lenght++;
        }       
    }
    if (lenght > maxLenght) {
        start = indStart;
        end = n - 1;
    }
    cout<<start + 1<<" "<<end + 1;
    return 0;
}