#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem link: https://usaco.org/index.php?page=viewproblem2&cpid=639

int main() {
    ifstream fin ("diamond.in");
    ofstream fout ("diamond.out");

    int N; fin >> N;
    int K; fin >> K;

    vector<int> sizes;
    for (int i = 0; i < N; i++) {
        int diamond; fin >> diamond;
        sizes.push_back(diamond);
    }
    
    sort(sizes.begin(), sizes.end());
    int counter = 0;
    int maxcount = 0;
    for (int i = 0; i < N; i++) {
        maxcount = max(counter, maxcount);
        counter = 0;
        for (int j = i+1; j < N; j++){
            if (abs(sizes[i] - sizes[j]) <= K) {
                counter++;
            }
        }
    }

    maxcount += 1;
    fout << maxcount << endl;
}
