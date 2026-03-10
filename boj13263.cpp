#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 /*
 n번째 나무만 자르고 나면, 그 이후는 필요한 충전 비용이 0이므로
  남은 나무들을 다 잘라버릴 수 있습니다.

DP를 다음과 같이 정의합시다.

DPi:
마지막으로 자른 나무가 i번 나무일 때 사용한 충전 비용의 최소값
DPi=minj<i(DPj+ai⋅bj)


bj는 j가 증가함에 따라 감소하므로, 위에서 설명한 형태와 동일합니다. 
Convex Hull Trick을 사용할 수 있습니다.
 */
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
 
int n;
ll a[100001];
ll b[100001];
ll dp[100001];
 
struct Line
{
    ll a, b; // a*x+b
    double start = 0.0; // 이 직선을 사용하기 시작하는 x좌표값
    bool operator<(Line l) const { return start < l.start; }
};
 
vector <Line> lv;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
 
    lv.push_back({ b[1],0,0.0 });
 
    for (int i = 2; i <= n; i++)
    {
        Line tmp = { 0,0,a[i] };
        Line res = *prev(upper_bound(lv.begin(), lv.end(), tmp));
        // 이분탐색으로 필요한 직선을 찾음
        
        dp[i] = res.a * a[i] + res.b;
 
        Line nxt = { b[i], dp[i], 0.0 };
        while (true)
        {
            Line prv = lv.back();
            double cross = (double)(prv.b - nxt.b) / (nxt.a - prv.a);
            // 새로 넣으려는 직선과(nxt) 현재 가장 뒤에 있는 직선(prv) 과의 교점
 
            if (cross <= prv.start)
            {
                // prv 시작점보다 교점의 x좌표가 작으면, prv는 필요없는 직선이다.
                lv.pop_back();
                continue;
            }
 
            nxt.start = cross;
            lv.push_back(nxt);
            break;
        }
    }
 
    cout << dp[n];
}
