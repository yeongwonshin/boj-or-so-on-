#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1) { 
            int x = i;
            while (x) {
                int d = x % 10;
                if (d == 3 || d == 6 || d == 9) ans++;
                x /= 10;
            }
        }
    }

    cout << ans;
}