#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=593

int main()
{
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int n; cin >> n;
    int x = 0, y = 0;
    
    vector<int> x_coords;
    vector<int> y_coords;
    vector<int> time;

    for (int i = 0; i < n; i++) {
        char direction; cin >> direction;
        int steps; cin >> steps;

        if (direction == 'N') {
            for (int i = 0; i < steps; i++) {
                y++;
                x_coords.push_back(x);
                y_coords.push_back(y);
            }

        } else if (direction == 'E') {
            for (int i = 0; i < steps; i++) {
                x++;
                x_coords.push_back(x);
                y_coords.push_back(y);
            }

        } else if (direction == 'S') {
            for (int i = 0; i < steps; i++) {
                y--;
                x_coords.push_back(x);
                y_coords.push_back(y);
            }

        } else if (direction == 'W') {
            for (int i = 0; i < steps; i++) {
                x--;
                x_coords.push_back(x);
                y_coords.push_back(y);
            }

        }
    }
    
    int ans = __INT8_MAX__;
    bool crossed = false;

    for (int i = 0; i < x_coords.size(); i++) {
        time.push_back(i);
    }
    
     for (int i = 0; i < x_coords.size(); i++) {
        for (int j = i + 1; j < x_coords.size(); j++) {
            if (x_coords[i] == x_coords[j]) {
                if (y_coords[i] == y_coords[j]) {
                    crossed = true;
                    ans = min(ans, abs(time[i] - time[j]));
                }
            }
        }
     }
     
    if (!crossed) {
        cout << -1;
    } else {
        cout << ans;
    }
}