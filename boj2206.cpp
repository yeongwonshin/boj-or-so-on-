#include <bits/stdc++.h>
using namespace std;

int n, m;
string arr[1000];

bool visited[1000][1000][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ans = INT_MAX;

void dfs(int x, int y, int dist, int breaked) {

    // 이미 찾은 답보다 길면 중단 (가지치기)
    if (dist >= ans) return;

    if (x == n-1 && y == m-1) {
        ans = min(ans, dist);
        return;
    }

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {

            // 빈칸일 때
            if (arr[nx][ny] == '0' && !visited[nx][ny][breaked]) {

                visited[nx][ny][breaked] = true;
                dfs(nx, ny, dist + 1, breaked);
                visited[nx][ny][breaked] = false; // 백트래킹
            }

            // 벽이고 아직 안 부쉈을 때
            if (arr[nx][ny] == '1' && breaked == 0 && !visited[nx][ny][1]) {

                visited[nx][ny][1] = true;
                dfs(nx, ny, dist + 1, 1);
                visited[nx][ny][1] = false; // 백트래킹
            }
        }
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    visited[0][0][0] = true;

    dfs(0, 0, 1, 0);

    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}