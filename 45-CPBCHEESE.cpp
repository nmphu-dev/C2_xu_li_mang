#include <bits/stdc++.h>
using namespace std;

int M, N, ans=0;
vector<vector<int>> a;
vector<vector<bool>> visited;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void f() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx>=0 && nx<M && ny>=0 && ny<N && !visited[nx][ny] && a[nx][ny]==0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

bool cnt() {
    vector<pair<int, int>> m;
    for(int i=1; i<M-1; ++i) {
        for(int j=1; j<N-1; ++j) {
            if(a[i][j]==1) {
                int cnt = 0;
                for(int k = 0; k < 4; ++k) {
                    int ni=i+dx[k], nj=j+dy[k];
                    if(visited[ni][nj]) cnt++;
                }
                if(cnt >= 2) m.push_back({i, j});
            }
        }
    }
    if(m.empty()) return false;
    for(auto [x, y]: m) {
        a[x][y] = 0;
        visited[x][y] = true;
    }
    return true;
}

int main() {
    cin >> M >> N;
    a.assign(M, vector<int>(N));
    for(int i=0; i<M; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> a[i][j];
        }
    }
    while(true) {
        visited.assign(M, vector<bool>(N, false));
        f();
        if (!cnt()) break;
        ans++;
    }
    cout << ans;
}
