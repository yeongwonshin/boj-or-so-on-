#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr int INF = 1e9 + 7;

int main() {
	fastio;
	int n; cin >> n;
	vector<int> v(n), DP(n, INF);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	auto Sol = [&](int i, auto&& Sol) -> int {
		if (i == 0) return v[0];
		int& ret = DP[i];
		if (ret != INF) return ret;
		return ret = max(Sol(i - 1, Sol), 0) + v[i];
	};
	
	int res = -INF;
	for (int i = 0; i < n; i++) res = max(res, Sol(i, Sol));
	cout << res << '\n';
}