#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000;
vector<int> adj[MAXV];
bool visited[MAXV];

void dfs_iterative(int start) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (visited[u]) continue;
        visited[u] = true;

        cout << u << " ";

        // 재귀 DFS와 같은 순서를 원하면 역순으로 push
        for (int i = adj[u].size() - 1; i >= 0; i--) {
            int v = adj[u][i];
            if (!visited[v]) {
                st.push(v);
            }
        }
    }
}
