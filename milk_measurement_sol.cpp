#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=761
 
int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    // variables defined
    int n; cin >> n;
    int b = 7, e = 7, m = 7, output = 0;
    vector<int> day;
    vector<int> adjust;
    vector<string> name;
    vector<bool> maxes = {false, false, false};
    vector<bool> new_maxes = {false, false, false};
 
    // input
    for (int i = 0; i < n; i++) {
        int d, a; cin >> d;
        string na; cin >> na;
        cin >> a;
        day.push_back(d);
        adjust.push_back(a);
        name.push_back(na);
    }
    
    // sorts everything in chronological order and adjusts the names and values accordingly 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (day[i] > day[j]) {
                //! whenever we make one change all other array are also changed
                int temp = day[i];
                day[i] = day[j];
                day[j] = temp;
 
                string tem = name[i];
                name[i] = name[j];
                name[j] = tem;
 
                temp = adjust[i];
                adjust[i] = adjust[j];
                adjust[j] = temp; 
            }
        }
    }
 
    //* not looking back at code anymore
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        if (name[i] == "Bessie") {
            b += adjust[i];
        } else if (name[i] == "Elsie") {
            e += adjust[i];
        } else if (name[i] == "Mildred") {
            m += adjust[i];
        }
        
        maximum = max(max(b, e), m);
        
        if (maximum == b) {
            new_maxes[0] = true;
        } else {
            new_maxes[0] = false;
        }
         
        if (maximum == e) {
            new_maxes[1] = true;
        } else {
            new_maxes[1] = false;
        } 

        if (maximum == m) {
            new_maxes[2] = true;
        } else {
            new_maxes[2] = false;
        } 

        if (maxes != new_maxes) {
            output++;
        }
        
        maxes = new_maxes;
    }

    cout << output << endl;
}