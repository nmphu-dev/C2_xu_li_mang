#include <bits/stdc++.h>
#define FOR1(i,a,b) for(ll i=a; i<b; ++i)
#define pb push_back
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    vector<ll> a(n);
    FOR1(i, 0, n) cin >> a[i];
    vector<vector<ll>> D;
    vector<ll> Dmin;
    FOR1(i, 0, n) {
        ll x = a[i];
        bool ck = false;
        FOR1(j, 0, D.size()) {
            if(x < Dmin[j]) {
                D[j].pb(i+1);
                Dmin[j] = x;
                ck = true;
                break;
            }
        }
        if(!ck) {
            D.pb({i+1});
            Dmin.pb(x);
        }
    }
    cout << D.size() << '\n';
    for(vector<ll> dd: D) {
        for(ll id: dd) cout << id << ' ';
        cout << "\n";
    }
}
