#include <bits/stdc++.h>
using namespace std;

int a[100000];

bool ck(int n) {
	int x = 8*n+1;
	int sq = sqrt(x);
	if(sq*sq==x && (!((-1+x)%2)) && (-1+x)!=0) return true;
	else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, ans; cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
	int i = 0;
	while(i < n) {
		if(ck(a[i])) {
			int t = 0;
			while(i<n && ck(a[i])) {
				t++;
				if(i==n or a[i+1]<a[i]) {
					i++;
					break;
				}
                i++;
			}
			ans = max(ans, t);
		} else i++;
	}
	cout << ans;
}
