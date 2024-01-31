#include <iostream>
#include <vector>
using namespace std;

// problem: cow tipping
// http://www.usaco.org/index.php?page=viewproblem2&cpid=689

    /* ! original code !
    void change (int i, int j, vector<vector<char>> &map){ 
        for (int x = i; x >= 0; x--){
            for (int y = j; y >= 0; y--){
                if (map[x][y] == 0){
                    map[x][y] = 1; 
                } else {
                    map[x][y] = 0;
                }
            }
        }
    }
    */
        
    
    // new code

    void change (int i, int j, vector<vector<char>> &map){
        for (int x = 0; x <= i; x++) {
            for (int y = 0; y <= j; y++) {
                if (map[x][y] == '0') {
                    map[x][y] = '1';
                } else {
                    map[x][y] = '0';
                }
            }
        }
    }


int main() 
{
    freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

    int n; 
    cin >> n;
    vector<vector<char>> map(n, vector<char> (n));
    // int map[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char cell;
            cin >> cell;
            map[i][j] = cell;
        }
    }
    
    int total_tips = 0;
    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            if (map[i][j] == '1'){
                change(i, j, map);
                total_tips++;
            }
        }
    }
    
    cout << total_tips;
}