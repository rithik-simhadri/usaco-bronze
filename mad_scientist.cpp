#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1012

int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    bool beginning = true;
    int startPoint = 0;

    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            if (beginning){
                startPoint++;
                beginning = false; 
            }
        } else {
            beginning = true;
        }
    }

    cout << startPoint;
}
