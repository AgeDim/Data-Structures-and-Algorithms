#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<string, stack<pair<int, int>>> z;
    stack<vector<string>> st;
    st.push({});
    string s;
    while(cin >> s){
        if(s == "{"){
            st.push({});
        }else if(s == "}"){
            for(const string& t : st.top()){
                z[t].pop();
            }
            st.pop();
        }else{
            int rs_data;
            unsigned long long eq = s.find('=');
            string ls = s.substr(0, eq);
            string rs = s.substr(eq + 1);


            if(rs[0] == '-' || '0' <= rs[0] && rs[0] <= '9'){
                rs_data = stoi(rs);
            }else{
                rs_data = z.count(rs) && !z[rs].empty() ? z[rs].top().first : 0;
                cout << rs_data << endl;
            }
            if(!z.count(ls)){
                z[ls] = stack<pair<int, int>>();
            }
            if(!z[ls].empty() && z[ls].top().second == st.size()){
                z[ls].top().first = rs_data;
            }else{
                z[ls].push({rs_data, st.size()});
                st.top().push_back(ls);
            }
        }
    }
    return 0;
}
