#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

    //https://codeforces.com/gym/102951/problem/A
    
int main()
{
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");
    
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }

    for (int i = 0; i < n; i++){
        cin >> y[i];
    }
    

    vector<int> distances;
    int biggest;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i < j){ 
                distances.push_back((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                // distances.push_back(pow((x[i] - x[j]), 2) + (y[i] - y[j])^2);
            }
        }
    }

    sort(distances.begin(), distances.end());
    cout << distances.back();
}