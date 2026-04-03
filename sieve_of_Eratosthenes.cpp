#include <bits/stdc++.h>
using namespace std;

vector<int> get_primes(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    // 🔹 함수 호출
    vector<int> primes = get_primes(n);

    int left = 0, right = 0;
    long long sum = 0;
    int count = 0;

    while (true) {
        if (sum >= n) {
            if (sum == n) count++;
            sum -= primes[left++];
        } else {
            if (right == primes.size()) break;
            sum += primes[right++];
        }
    }

    cout << count << "\n";
    return 0;
}