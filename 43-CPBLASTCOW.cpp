#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    unordered_map<string, ll> mp;
    mp.insert(make_pair("Bessie", 0));
    mp.insert(make_pair("Elsie", 0));
    mp.insert(make_pair("Daisy", 0));
    mp.insert(make_pair("Gertie", 0));
    mp.insert(make_pair("Annabelle", 0));
    mp.insert(make_pair("Maggie", 0));
    mp.insert(make_pair("Henrietta", 0));
    ll n; cin >> n;
    while(n--) {
        string s; ll n;
        cin >> s >> n;
        mp[s] += n;
    }
    ll mi=LLONG_MAX, res=LLONG_MAX;
    string ans;
    for(pair<string, ll> i: mp) {
        mi = min(mi, i.second);
    }
    for(pair<string, ll> i: mp) {
        if(i.second>mi && i.second<res) {
            res = i.second;
            ans = i.first;
        }
    }
    ll cnt = 0;
    for(pair<string, ll> i: mp) {
        if(i.second==res) cnt++;
        if(cnt>1) {
            cout << "Tie";
            break;
        }
    }
    cout << ans;
}
