#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using LL = long long;
// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=1301

int main(void) 
{
    LL N; cin >> N;
    LL K; cin >> K;
    vector<LL> day(N);

    for (LL i = 0; i < N; i++) {
        cin >> day[i];
    }
    
    LL paid = 0;
    LL restart = 0;
    LL keep = 0;
    for (LL i = 0; i < N; i++) {
        if (i == 0) {
            // meaning that its the first day bessie is watchin; which means that there is one choice which is just to start a subscription
            paid += K + 1;
        } else {
            // either start new subscription or not 
            // whichever one is less money we will choose that
            // for example if we started it on day 5 (we would pay K on day 5) and today is day 7 it would be 2 moonies extra to pay
            paid += min(K + 1, day[i] - day[i - 1]);
        }
    } 

    cout << paid << endl;
}