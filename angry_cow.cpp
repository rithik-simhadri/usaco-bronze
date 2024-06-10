#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=592

int explosions (int LOR, int START, vector<int> POS, int N) {
    int PREV = START, NEXT = 0, RAD = 1;
    bool END = true;
    while (END) {
        NEXT = PREV;
        while (NEXT + LOR >= 0 && NEXT + LOR < N && abs(POS[NEXT + LOR] - POS[PREV]) <= RAD) {
            NEXT += LOR;
        }
        
        if (NEXT == PREV) {
            END = false;
            break;
        }

        RAD++;
        PREV = NEXT;
    }
    
    return abs(PREV - START);
}

int main() {
    ifstream fin ("angry.in");
    ofstream fout ("angry.out");

    int N; fin >> N;
    
    vector<int> haybales;
    for (int i = 0; i < N; i++) {
        int pos; fin >> pos;
        haybales.push_back(pos);
    }

    sort(haybales.begin(), haybales.end());
    
    int ANS = 0;
    for (int i = 0; i < N; i++) {
        ANS = max(ANS, explosions(-1, i, haybales, N) + explosions(1, i, haybales, N) + 1);
    }

    fout << ANS << endl;
}