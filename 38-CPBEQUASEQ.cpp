#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[1000000];

vector<ll> uoc(ll n) {
    vector<ll> d;
    for(ll i=1; i*i<=n; ++i) {
        if(!(n%i)) {
            d.push_back(i);
            if(i != n/i) d.push_back(n/i);
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, S=0, ans=0, curr=0; cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        S += a[i];
    }
    if(S == 0) {
        for(int i=0; i<n; ++i) {
            curr += a[i];
            if(curr==0) {
                ++ans;
                curr = 0;
            }
        }
    } else {
        vector<ll> d = uoc(S);
        sort(d.begin(), d.end());
        ans = 1;
        for(ll i=0; i<d.size(); ++i) {
            bool ck1 = true;
            for(ll j=0; j<n; ++j) {
                if(a[j]>d[i]) {
                    ck1 = false;
                    break;
                }
            }
            if(!ck1) continue;
            ll x=0; bool ck2=true;
            curr=0;
            for(ll k=0; k<n; ++k) {
                curr += a[k];
                if(curr>d[i]) {
                    ck2 = false;
                    break;
                } else if(curr==d[i]) {
                    ++x;
                    curr = 0;
                }
            }
            if(ck2 && (!curr)) ans = max(ans, x);
        }
    }
    cout << ans;
}
