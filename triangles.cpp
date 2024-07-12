// #include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
 
// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=1011

int main() {
    ifstream fin ("triangles.in");
    ofstream fout ("triangles.out");
    int N; fin >> N;

    /*
        vector<pair<int, int>> XY_COORDS(N);
        for (int i = 0; i < N; i++) {
            cin >> XY_COORDS[i].first;
            cin >> XY_COORDS[i].second;
        }    
    */
   
   vector<int> X;
   vector<int> Y;
   for (int i = 0; i < N; i++) {
        int coordx, coordy; fin >> coordx >> coordy;
   }
 
    double ANS = 0, area = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                // if the triangle is a right triangle
                if (Y[i] == Y[j] && X[i] == X[k]) {
                    // none of the points are equal to each other
                    if (i != j && i != k && j != k) {
                        area = abs((X[j] - X[i]) * (Y[k] - Y[i]));
                        ANS = max(ANS, area);
                    }                    
                }
            }
        }
    }

    fout << 2*area << endl;
}