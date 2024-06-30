#include <iostream>
#include <fstream>
using namespace std;

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=963

int main() {
    ifstream ccin("gymnastics.in");
    ofstream ccout("gymnastics.out");

    int K; ccin >> K;
    int N; ccin >> N;

    // upper bound of input becuase no variable size for arrays
    int ranks[10][20];
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            ccin >> ranks[i][j]; 
            ranks[i][j]--;
        }
    }
    
    int data[20][20] = {0};
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                data[ranks[i][j]][ranks[i][k]]++;       
            }
        }
    }
    
    int ANS = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (data[i][j] == K) {
                ANS++;    
            }            
        }
    }

    ccout << ANS << endl;   
}