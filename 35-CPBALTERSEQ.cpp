#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[1000005];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, ans, curr, cnt=0; cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    curr=(a[1]!=0);
    ans = curr;
    for(int i=1; i<n; ++i) {
        if(1LL*a[i]*a[i-1] < 0) curr++;
        else curr = (a[i]!=0);
        ans = max(ans, curr);
    }
    curr=(a[1]!=0);
    for(int i=1; i<n; ++i) {
        if(1LL*a[i]*a[i-1] < 0) curr++;
        else curr = (a[i]!=0);
        if(curr==ans) cnt++;
    }
    if(ans==0) cout << "0 0";
    else cout << cnt << ' ' << ans;
}
