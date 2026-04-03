#include <bits/stdc++.h>
using namespace std;

//bottom-up dp로 풂.
//탑다운 방식이랑 시간복잡도 동일.
//단 탑다운은 필요한 것만 계산하고(메모이제이션) 바텀업은 모든 상태 계산.
const int INF = 1e9;

int solve_no_swap_bottom_up(string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 길이 1은 이미 0이므로 그대로 둠

    // 길이 2 이상부터 채움
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;

            if (s[l] == s[r]) {
                dp[l][r] = dp[l+1][r-1];
            } else {
                dp[l][r] = min({
                    dp[l+1][r] + 1,
                    dp[l][r-1] + 1,
                    dp[l+1][r-1] + 1
                });
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    int ans = solve_no_swap_bottom_up(s);

    // swap 1번 허용
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) continue;

            swap(s[i], s[j]);
            ans = min(ans, solve_no_swap_bottom_up(s) + 1);
            swap(s[i], s[j]);
        }
    }

    cout << ans << "\n";
    return 0;
}