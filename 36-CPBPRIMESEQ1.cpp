#include<bits/stdc++.h>
using namespace std;

int a[10005];
bool isPrime(int n) {
    if(n==2 || n==3) return true;
    if(n<3 || !(n%2) || !(n%3)) return false;
    for(int i=5; i*i <= n; i+=6)
        if(!(n%i) || !(n%(i+2))) return false;
    return true;
}
int main() {
    int n; cin >> n;
    int ans=0, cnt=0, curr=0, x;
    for(int i=0; i<n; ++i) {
        cin >> x;
        if(isPrime(x)) curr++;
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
