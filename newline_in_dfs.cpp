void dfs(int node) {
    visited[node] = true;
    cout << node << ' ';

    bool isLeaf = true;

    for (int i : graph[node]) {
        if (!visited[i]) {
            isLeaf = false;
            dfs(i);
        }
    }

    if (isLeaf) cout << '\n';
}