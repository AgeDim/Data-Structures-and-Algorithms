#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int main() {
    bool status = true;
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> map(n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        map[x - 1].push_back(y - 1);
        map[y - 1].push_back(x - 1);
    }
    std::vector<bool> worked(n, false);
    std::vector<int> halves(n, 0);
    for (int i = 0; i < n; i++) {
        worked[i] = true;
        std::queue<int> workedQ;
        workedQ.push(i);
        if (halves[i] == 0)halves[i] = 1;
        while (!workedQ.empty()) {
            int actual = workedQ.front();
            workedQ.pop();

            for (int mates: map[actual]) {
                if (!worked[mates]) {
                    worked[mates] = true;
                    workedQ.push(mates);
                    if (halves[actual] == 1) {
                        halves[mates] = 2;
                    } else {
                        halves[mates] = 1;
                    }
                }else {
                    if (halves[actual] == halves[mates])status = false;
                }
            }
        }

        if (status == false)break;
    }

    if (status == true) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
}