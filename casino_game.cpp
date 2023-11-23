#include <iostream>
#include <vector>
using namespace std;

// B. Playing in a Casino

// https://codeforces.com/contest/1808/problem/B

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        int b[n][m];
    
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> b[i][j];
            }
        }
    
        int total = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (i != j){
                    for (int k = 0; k < m; k++){
                        total += abs(b[i][k] - b[j][k]);                   
                    }   
                }
            }
        }
        cout << total << endl;
    }
}