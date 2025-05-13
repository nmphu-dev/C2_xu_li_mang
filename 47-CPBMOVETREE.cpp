#include <bits/stdc++.h>
#define FOR1(i,a,b) for(ll i=a; i<b; ++i)
using namespace std;
using ll = long long;

ll a[100][100];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll m, n, t; cin >> m >> n >> t;
    FOR1(i, 0, m) {
        FOR1(j, 0, n) cin >> a[i][j];
    }
    vector<vector<bool>> giu(m, vector<bool>(n, false));
    FOR1(i, 0, m) {
        ll j=0;
        while(j < n) {
            if(a[i][j] == 0) {
                j++;
                continue;
            }
            ll curr = a[i][j];
            ll start = j;
            while((j<n) && (a[i][j] == curr)) j++;
            ll len = j-start;
            if(len>=t) FOR1(k, start, j) giu[i][k] = true;
        }
    }
    FOR1(j, 0, n) {
        ll i = 0;
        while(i < m) {
            if(a[i][j] == 0){
                i++;
                continue;
            }
            ll curr = a[i][j];
            int start = i;
            while((i<m) && (a[i][j]==curr)) i++;
            ll leng = i-start;
            if(leng >= t) for(int k=start; k<i; k++) giu[k][j] = true;
        }
    }
    int cnt = 0;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if((a[i][j]!= 0) && (!giu[i][j])) cnt++;
        }
    }
    cout << cnt;
}
