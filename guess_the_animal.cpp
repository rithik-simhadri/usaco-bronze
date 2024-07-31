// #include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ifstream fin ("guess.in");
    ofstream fout ("guess.out");
// cin 
    int N; fin >> N;
    vector<vector<string>> characteristics(N);

    for (int i = 0; i < N; i++) {
        string name; fin >> name;
		int K; fin >> K;
		for (int j = 0; j < K; j++) {
			string charac; fin >> charac;
			characteristics[i].push_back(charac);
		}
    }

    int ANS = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int same = 0;
			for (const auto &characone : characteristics[i]) {
				for (const auto &charactwo : characteristics[j]) {
					if (characone == charactwo) {
						same++;
						break;
			    	}
			    }
            }
            ANS = max(ANS, same);
        }
    }

    // plus one for the question that makes the feasible set confirmed one answer
    // other wise there will be 2 answers

    fout << ANS + 1 << endl;   
}