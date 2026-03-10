#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,cur;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = LLONG_MIN;
  /*컴파일러는 내가 화면에 보고 있는 코드를 컴파일하는 게 아니라 
  디스크에 저장된 파일만 컴파일한다.*/
for (ll i = 0; i < n; i++) {
        cur = max(a[i], cur + a[i]);
    //이전 구간을 이어갈지, 여기서 새 구간을 시작할지 결정.    
        ans = max(ans, cur);//이게 있기에 음수가 나와도 ㄱㅊ.
    }

    cout << ans << "\n";
}