#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;

ll n, k, t, ans = 1e18;
vector<pair<ll, ll> > adj[MAXN];

ll sz[MAXN];
ll sum[MAXN], dp[MAXN];
ll up_sum[MAXN], updp[MAXN];

void dfs1(int u, int p) {
    sz[u] = 1;
    for (auto& [v,w]: adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp[u] += dp[v] + sz[u] * (sum[v] + w * sz[v]) + sz[v] * sum[u];
        sz[u] += sz[v], sum[u] += sum[v] + w * sz[v];
    }
}


void dfs2(int u, int p) {
    ans = min(ans, max(dp[u], updp[u]));
    for (auto& [v,w]: adj[u]) {
        if (v == p) continue;
        ll val = up_sum[u] + (sum[u] - (sum[v] + w * sz[v]));
        up_sum[v] = val + (n - sz[v]) * w;
        updp[v] = t - dp[v] - (sum[v] * (n - sz[v]) + w * sz[v] * (n - sz[v]) + sz[v] * val);
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}), adj[v].push_back({u, w});
    }

    dfs1(1, 0);
    if (k == 1) return cout << dp[1], 0;
    t = dp[1];
    dfs2(1, 0);
    cout << ans << '\n';
    return 0;
}

