#include <iostream>
#include <vector>
#include <algorithm>

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=1251

using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;
    vector<ll> ci;
    for (ll i = 0; i < n; i++){
        ll c; cin >> c;
        ci.push_back(c);
    }

    sort(ci.begin(), ci.end());
    
    ll possible_revenue = 0;
    ll max_revenue = 0;
    ll best_value = 0;
    for (ll i = 0; i < n; i++) {
        max_revenue = max(possible_revenue, ((n - i) * ci[i]));
        if (max_revenue != possible_revenue){
            best_value = ci[i];
            possible_revenue = max_revenue;
        }
    }
    
    cout << max_revenue << " " << best_value << endl;
}