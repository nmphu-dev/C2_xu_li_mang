#include <bits/stdc++.h>
using namespace std;

int ve[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, n, cnt1=0, cnt2=0; cin >> m >> n;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) cin >> ve[i][j];
    }
    for(int i=0; i<m-1; ++i) {
        for(int j=0; j<n-1; ++j) {
            int a = ve[i][j];
            int b = ve[i][j+1];
            int c = ve[i+1][j];
            int d = ve[i+1][j+1];
            if(a==3 && b==1 && c==0 && d==2) cnt1++;
            else if(a==2 && b==0 && c==1 && d==3) cnt2++;
        }
    }
    cout << cnt1 << ' ' << cnt2 << '\n';
}
