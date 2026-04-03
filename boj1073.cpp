#include <bits/stdc++.h>
using namespace std;
//bottom up dp로 풂.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;

    int ans = 0;

    while (N > 0) {
        int half = 1 << (N - 1);
        int block = half * half;

        if (r < half && c < half) {
            // 1사분면
        }
        else if (r < half && c >= half) {
            ans += block;
            c -= half;
        }
        else if (r >= half && c < half) {
            ans += 2 * block;
            r -= half;
        }
        else {
            ans += 3 * block;
            r -= half;
            c -= half;
        }

        N--;
    }

    cout << ans << "\n";
}