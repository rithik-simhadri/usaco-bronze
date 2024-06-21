#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem-link: https://cses.fi/problemset/task/1622/

vector<string> generated;

int permute(string N, vector<string> generated) {
    do {
        generated.push_back(N);
    } while (next_permutation(N.begin(), N.end()));
}


int main() {
    string N; cin >> N;
    // for lexiographical order
    sort(N.begin(), N.end());
    
    permute(N, generated);

    // output
    cout << generated.size();
    for (int i = 0; i < generated.size(); i++) {
        cout << generated[i] << endl;
    }
}