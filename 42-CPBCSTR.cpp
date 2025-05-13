#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s; getline(cin, s);
    set<char> res;
    int n=s.size();
    for(int i=0; i<n; ++i) {
        if(s[i]==' ') continue;
        if('A'<=s[i]<='Z') s[i] = tolower(s[i]);
        res.insert(s[i]);
    }
    cout << res.size();
}
