#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    long long ans = 0;

    for(int top = 0; top < n; top++) {

        vector<int> colSum(m, 0);

        for(int bottom = top; bottom < n; bottom++) {

            for(int j = 0; j < m; j++)
                colSum[j] += a[bottom][j];

            unordered_map<int,int> mp;
            mp[0] = 1;

            int prefix = 0;

            for(int j = 0; j < m; j++) {

                prefix += colSum[j];

                if(mp.count(prefix - k))
                    ans += mp[prefix - k];

                mp[prefix]++;
            }
        }
    }

    cout << ans << "\n";
}