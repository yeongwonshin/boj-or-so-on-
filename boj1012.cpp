#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int sol(int m, int n, vector<vector<int>>& farm) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int worm = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(farm[i][j] && !visited[i][j]) {
                worm++;
                queue<pair<int,int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while(!q.empty()) {
                    auto [cy, cx] = q.front();
                    q.pop();

                    for(int d = 0; d < 4; ++d) {
                        int nx = cx + dx[d];
                        int ny = cy + dy[d];

                        if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
                           farm[ny][nx] && !visited[ny][nx]) {
                            visited[ny][nx] = true;
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }
    }

    return worm;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int m, n, k;
        cin >> m >> n >> k;

        vector<vector<int>> farm(n, vector<int>(m, 0));

        for(int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            farm[y][x] = 1;
        }

        cout << sol(m, n, farm) << "\n";
    }

    return 0;
}
