#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool canMakeSum(ll x, ll target, ll startFactor) {
    // x 자체를 마지막 인수 하나로 쓰는 경우
    if (x == target) return true;

    // x를 startFactor 이상인 인수들로 나누어 보며 탐색
    for (ll f = startFactor; f * f <= x; f++) {
        if (x % f == 0) {
            ll other = x / f;

            // f를 하나 선택했으므로,
            // 나머지 other를 다시 인수분해해서 target - f 를 만들 수 있는지 확인
            if (canMakeSum(other, target - f, f)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll A, B;
        cin >> A >> B;

        // 이 코드는 양의 정수 A만 대상으로 한 "인수 합 탐색" 예시
        if (A <= 0) {
            cout << "no\n";
            continue;
        }

        if (canMakeSum(A, B, 2) || A == B) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}