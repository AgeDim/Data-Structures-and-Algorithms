#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, k;
	int last = 0;
    cin >> a >> b >> c >> d >> k;
    for(int i=0;i<k;i++){
        if(a*b <= c){
            a=0;
            break;
        }else{
            a =a*b - c;
            if(a > d){
            a = d;
            }
        if(a == last){break;}
        }
   	last = a;
    }
    cout<<a;
}