#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n,s, res = 0;
    int l[int(1e6)+100];
    cin >> n >>s;
    for(int i = 1;i<=n; i++){
        cin >> l[i];
    }
    sort(l+1, l+n+1);
    reverse(l+1,l+n+1);

    for(int i =1; i<=n;i++){
        res += l[i] * (i%s !=0);}
        cout << res;

}