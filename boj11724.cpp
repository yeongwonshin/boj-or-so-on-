#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int n, m; cin >> n >> m;
	vector adj(n + 1, vector(0, 0));
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector visited(n + 1, 0);
	auto DFS = [&](int cur, auto&& DFS) -> void {
		visited[cur] = 1;
		for (int nxt : adj[cur]) if (!visited[nxt]) DFS(nxt, DFS);
	};
	
	int res = 0;
	for (int i = 1; i <= n; i++) if (!visited[i]) DFS(i, DFS), res++;
	cout << res << '\n';
}