#include <iostream>
#include <vector>

int pig;
std::vector<int> y;
std::vector<int> z;
int res = 0;

void minOfPig(int a) {
    if (z[a] != -1) {
        if (z[a] == pig) {
            res += 1;
        }
        return;
    }
    z[a] = pig;
    minOfPig(y[a]);
}

int main() {
    int n, i;
    std::cin >> n;
    z.resize(n, -1);
    y.resize(n);

    for (int j = 0; j < n; ++j) {
        std::cin >> i;
        i--;
        y[j] = i;
    }


    for (int j = 0; j < n; ++j) {
        pig = j;
        minOfPig(j);
    }

    std::cout << res << std::endl;
    
}