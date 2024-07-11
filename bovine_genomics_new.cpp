#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=736

int main() {
	ifstream fin ("cownomics.in");
    	ofstream fout ("cownomics.out");
	
	int n, m;
	fin >> n >> m;

    	vector<vector<char>> plain(n, vector<char>(m));
	vector<vector<char>> spots(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
            		fin >> spots[i][j];
        	}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
            		fin >> plain[i][j];
        	}
	}

	int ANS = 0;
	for (int i = 0; i < m; i++) {
		bool duplicate = false;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (spots[j][i] == plain[k][i]) {
					duplicate = true;
					break;
				}
			}
		}

		if (!duplicate) ANS++;
	}

	fout << ANS << endl;
}
