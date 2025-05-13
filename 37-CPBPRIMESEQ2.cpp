#include<bits/stdc++.h>
using namespace std;

int a[10005];
bool p[1000005];

void sieve(int n) {
    for(int i=2; i<=n; ++i) p[i] = true;
    for(int i=2; i*i<=n; ++i) {
        if(p[i]) {
            for(int j=i*i; j<=n; j+=i) p[j] = false;
        }
    }
}

int main() {
    sieve(1000000);
    int n; cin >> n;
    int ans=0, cnt=0, curr=0, x;
    for(int i=0; i<n; ++i) {
        cin >> x;
        if(p[x]) curr++;
        else {
            if(curr) {
                if(curr > ans) {
                    ans = curr;
                    cnt = 1;
                }
                else if(curr == ans) cnt++;
                curr = 0;
            }
        }
    }
    if(curr) {
        if(curr > ans) {
            ans = curr;
            cnt = 1;
        }
        else if(curr==ans) cnt++;
    }
    cout << cnt << ' ' << ans;
}
