#include <string>
#include <iostream>

using namespace std;

int main() {
    int n = 0;
    string a[100];
    while(cin >> a[n]){
        n+=1;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[j-1] + a[j]< a[j] + a[j-1]){
            string temp = a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout << a[i];
    }
}