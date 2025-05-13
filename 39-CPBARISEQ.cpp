#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, mx=0, d=0; cin >> n;
    vector<ll> a(n);
    for(ll i=0; i<n; ++i) cin >> a[i];
    if(n < 3) {
        cout << 0;
        return 0;
    }
    vector<unordered_map<ll, ll>> b(n);
    for(ll i=0; i<n; ++i) {
        for (ll j=0; j<i; ++j) {
            ll curr = a[i]-a[j];
            ll x = 2;
            if(b[j].count(curr)) x = b[j][curr] + 1;
            b[i][curr] = max(b[i][curr], x);
            if(x > mx) {
                mx = x;
                d = curr;
            }
            if(x == mx) {
                mx = x;
                d = max(curr, d);
            }
        }
    }
    
    if(mx<3) cout << 0;
    else cout << mx << ' ' << d;
}
