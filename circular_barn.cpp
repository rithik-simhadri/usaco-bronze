#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// problem: circular barn
// link: http://www.usaco.org/index.php?page=viewproblem2&cpid=616

int main()
{
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n; 
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; i++){
        cin >> r[i];
    }
    

    vector<int> distances;
    int total_distance = 0;
    int doors = n - 1;
    int rotation_element;
    int min_distance = 0;

    for (int i = 0; i < n; i++){
        for (int j = n - 1; j >= 0; j--){
            if (j >= 1){
                total_distance += r[j] * doors;
                // cout << total_distance << endl;
                doors--;
            } else {
                doors = n - 1;
                distances.push_back(total_distance);
                total_distance = 0;

                rotation_element = r[0];
                for (int k = 0; k < n - 1; k++){
                    r[k] = r[k + 1];
                }
                r[n - 1] = rotation_element;
            }    
        }
    }

    sort(distances.begin(), distances.end());
    cout << distances[0] << endl;
}