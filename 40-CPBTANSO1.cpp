#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x;  cin >> n;
    map<int,int> f;
    while(n--) {
        cin >> x;
        f[x]++;
    }
    for(pair<int,int> ii: f) cout << ii.first << ' ' << ii.second << '\n';
}
