#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int n; cin >> n;
	
	auto F = [](int n, int a, int b, auto&& F) -> void {
		if (!n) return;
		F(n - 1, a, 6 - a - b, F);
		cout << a << ' ' << b << '\n';
		F(n - 1, 6 - a - b, b, F);
	};
	
	cout << (1 << n) - 1 << '\n';
	F(n, 1, 3, F);
}