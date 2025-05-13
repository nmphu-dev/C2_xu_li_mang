#include<bits/stdc++.h>
using namespace std;

char mau[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0; cin >> n;
    for(int i=0; i<n; ++i) cin >> mau[i];
    for(int i=0; i<n-1; ++i) {
        if(mau[i]==mau[i+1]) {
            ans++;
            mau[i+1]='Y';
        }
    }
    cout << ans;
}
