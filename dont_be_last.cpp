#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
using namespace std;

// problem: dont be last!
// link: http://www.usaco.org/index.php?page=viewproblem2&cpid=687

int main()
{
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int n; cin >> n;
    map<string, int> cows;
    cows["Bessie"] = 0;
    cows["Elsie"] = 0;
    cows["Daisy"] = 0;
    cows["Gertie"] = 0;
    cows["Annabelle"] = 0;
    cows["Maggie"] = 0;
    cows["Henrietta"] = 0;

    for (int i = 0; i < n; i++){
        string cow; cin >> cow;
        int integer; cin >> integer;
        if (n == 1){
            cout << cow;
            return 0;
        }


        cows[cow] += integer;
        // cout << endl;
        // cout << cows[cow] << cow << endl;
    }
    
    vector<pair<int, string>> converted_cows;
    
    for (auto i : cows) {
        converted_cows.push_back(make_pair(i.second, i.first));
    }
    sort(converted_cows.begin(), converted_cows.end());


    int counter = 0;
    int minimal = 0;
    for (int i = 0; i < n; i++){
        if (counter == 2){
            break;
        }        

        if (converted_cows[i].first > minimal){
            minimal = converted_cows[i].first;
            counter++;
        }
    }
    
    int amt = 0;
    for (int i = 0; i < n; i++){
        if (converted_cows[i].first == minimal){
            amt++;
        }
    }
    
    if (amt >= 2){
        cout << "Tie" << endl;
    }
    
    else {
        for (int i = 0; i < n; i++){
            if (converted_cows[i].first == minimal){
                cout << converted_cows[i].second << endl;
            }
        }
    }
}