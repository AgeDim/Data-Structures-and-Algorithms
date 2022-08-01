#include <iostream>

int n;

int graph[1001][1001];
int nGraph[1001][1001];
int worked[1001];

void methodOfSize(int x, bool mode){
    worked[x] = 1;
    for (int i = 0; i < n; ++i){
        if (mode){
            if (!worked[i] && nGraph[i][x]) {
                methodOfSize(i, mode);
            }
        }
        else{
            if (!worked[i] && nGraph[x][i]){
                methodOfSize(i, mode);
            }
        }
    }
}


bool statusOfComplete(){
    for (int i = 0; i < n; ++i){
        if (!worked[i])
            return false;
    }
    return true;
}

int decision(int f, int l) {
    while (f < l) {
        int half = (f + l) / 2;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (graph[i][j] <= half) {
                    nGraph[i][j] = 1;
                }
                else{
                    nGraph[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < 1001; ++i){
            worked[i] = 0;
        }
        methodOfSize(0, false);

        bool flag = false;
        if (statusOfComplete()) {
            for (int i = 0; i < 1001; ++i){
                worked[i] = 0;
            }
            methodOfSize(0, true);
        if (!statusOfComplete()){flag = true;}
                
        }
        else {
            flag = true;
        }

        if (!flag) {
            l = half;
        }
        else{
            f = half + 1;
        }
    }
    return f;
}




int main()
{
    std::cin >> n;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
        }
    }

    std::cout << decision(0, 1000000009) << std::endl;

    return 0;
}