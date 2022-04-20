#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_cow(vector<int> const& a, int c, int k){
    c--;
    int first = a[0];
    for(int i = 1;i < a.size(); i++) {
        if (a[i] - first >= k) {
            c--;
            first = a[i];
        }
    }
    bool res = (c <=0);
    return res;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> z(n);
    for(auto &x: z){
        cin >> x;
    }
    sort(z.begin(),z.end());

    int d = 0, f= (int)1e9 + 1;
    while((f-d)>1){
        int l = (d+f) / 2;
        if(check_cow(z, c, l)){
            d = l;
        }else{
            f = l;
        }
    }
    cout << d;
}