#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main() {
    ll Q; cin >> Q;
    map<ll, ll> a;

    for (ll i = 0; i < Q; i++) {
        ll qnum; cin >> qnum;
        if (qnum == 0) {
            ll k; cin >> k;
            ll v; cin >> v;
            a[k] = v; 
        } else {
            ll k; cin >> k;
            cout << a[k] << endl;
        }
    }
}