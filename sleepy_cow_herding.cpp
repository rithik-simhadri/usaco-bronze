#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=915

int main(void) {
    freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

    vector<int> pos(3);
    int g1, g2;
    for (int i = 0; i < 3; i++) cin >> pos[i];

    sort(pos.begin(), pos.end());
    g1 = pos[1] - pos[0] - 1;
    g2 = pos[2] - pos[1] - 1;

    if ((g1 == 0 && g2 != 0) || (g1 != 0 && g2 == 0)){
        cout << 2 << endl;
        int maximum2 = max(g1, g2);
        cout << maximum2 << endl;
    } else {
        int minimum = min(min(g1, g2), 2);
        int maximum = max(g1, g2);
        cout << minimum << endl << maximum << endl;
    }
}