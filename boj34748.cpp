#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;

ll n, k, t, ans = 1e18;
vector<pair<ll, ll> > adj[MAXN];

ll sz[MAXN];//서브트리 노드 개수
ll sum[MAXN], dp[MAXN];
/*sum[u]: u의 서브트리의 간선 가중치 합/dp[u]: 서브트리 내부 쌍의 거리 합
sum[u] = Σ dist(u, x)
         x ∈ subtree(u)
dp[u] = Σ dist(x, y)
         x, y ∈ subtree(u), x < y
*/
ll up_sum[MAXN], updp[MAXN];
//u에서 부모쪽으로 가는 간선의 가중치 합,
//u에서 부모쪽으로 가는 간선의 가중치 합을 제외한 나머지 간선들의 가중치 합

void dfs1(int u, int p) {
    sz[u] = 1;//자기자신 포함
    for (auto& [v,w]: adj[u]) {
        if (v == p) continue;//부모로 가는 간선은 제외
        dfs1(v, u);//자식 먼저 계산
        dp[u] += dp[v] + sz[u] * (sum[v] + w * sz[v]) + sz[v] * sum[u];
        /*sum[v] + w * sz[v]: v의 서브트리의 간선 가중치 합 + u에서 v로 가는 간선의 가중치 * v의 서브트리 노드 개수
sz[u] * (sum[v] + w * sz[v]): u의 서브트리의 노드 개수 * (v의 서브트리의 간선 가중치
        */
        sz[u] += sz[v];
        sum[u] += sum[v] + w * sz[v];
    
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

