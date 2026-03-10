#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool visited[101];
int cnt;

void dfs(int u) {
    visited[u] = true;
    cnt++;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
/*dfs는 visited로 인해 중복 호출이 방지되므로 O(N)
 그래서 이 코드의 총 시간 복잡도는 O(N+M)*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;  
    cin >> M;  

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    cout << cnt - 1 << '\n';//1번 컴은 제외하고 세야함. 
    return 0;
}
