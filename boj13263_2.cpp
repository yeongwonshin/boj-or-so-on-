#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*
만약 Ai가 i가 증가함에 따라 역시 증가한다면, 
굳이 모든 직선을 가지고 있을 필요가 없습니다. 
앞에 필요없어진 직선은 그냥 버리면 되기 때문입니다. 

따라서 이 경우 O(n)
에 구현할 수 있게 됩니다.
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
 
deque <Line> lv;
 
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
        while (lv.size() > 1 && lv[1].start <= a[i]) lv.pop_front();
 
        Line res = lv.front();
    
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
