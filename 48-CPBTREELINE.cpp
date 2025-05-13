#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, ans=0; cin >> n;
    vector<ll> h(n);
    vector<ll> d(n,0);
    for(ll i=0; i<n; ++i) cin >> h[i];
    stack<ll> st;
    for(ll i=0; i<n; ++i) {
        ll x = 0;
        while(!st.empty() && h[st.top()] < h[i]) {
            x = max(x, d[st.top()]);
            st.pop();
        }
        if(st.empty()) d[i] = 0;
        else d[i] = x + 1;
        ans = max(ans, d[i]);
        st.push(i);
    }
    cout << ans;
}
