#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    
    vector<int> W;
    for (int i = 0; i < N * 2; i++) {
        int num; cin >> num;
        W.push_back(num);
    }
    
    sort(W.begin(), W.end());
    int counter = 0;
    int ANS = __INT8_MAX__, TI = 0;
    for (int i = 0; i < N*2; i++) {
        for (int j = i+1; j < N*2; j++) {
            vector<int> left;
            for (int k = 0; k < N*2; k++) {
                if (k != i && k != j) {
                    left.push_back(W[k]);
                }
            }
            
            TI = 0;
            // no left.size()-2 because 2 of the single kayaks are already taken out no need to take out 2 more
            for (int l = 0; l < left.size(); l += 2) {
                TI += abs(left[l+1] - left[l]);
            } 

            ANS = min(ANS, TI);
        }
    }

    cout << ANS;
}