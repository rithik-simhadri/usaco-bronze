#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
 
    int n;
    vector<string> stringSplitted;
    string colors;
    set<string> noDups;

    cin >> n >> colors;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n - i; j++){
            stringSplitted.push_back(colors.substr(j, i));
            noDups.insert(colors.substr(j, i));
            // cout << i << " " << j << endl;
        }

        if (noDups.size() == stringSplitted.size()){
            cout << i << endl;
            break;    
        } else {
            noDups.erase(noDups.begin(), noDups.end());
            stringSplitted.erase(stringSplitted.begin(), stringSplitted.end());
        }
        
    }
}
