#include <iostream> 
#include <algorithm> 
#include <cstring> 
using namespace std;

typedef long long ll;

int N, M, dp[301][1<<18], m;
//왼쪽, 위, 왼쪽위만 살피면 되기에(2x2만 지우면 되기에) 1<<M+1
const int mod = 1e9 + 7; 
// 격자판에서의 비트마스크 dp 
int sol(int idx, int st) {
    //idx: 현재 칸 번호(격자를 일자로 폄
    // st:현재칸 바로 이전까지의 비트마스크
     int& ret = dp[idx][st]; 
//dp[idx][st]: idx칸까지 st상태로 채우는 방법의 수
//st의 최하위비트가 바로 왼쪽칸, 1<<M-1이 바로 위칸, 1<<M이 왼쪽 위칸

     if (ret != -1) return ret; 
     //이미 계산된 상태면 재사용(메모이제이션)
     if (idx == N * M) return ret = 1; 
    //단 하나의 2x2없이 모든 칸에 대해 선택을 끝낸 상태
     if (idx % M) //현재 칸이 첫 열이 아닐 때만 
       if ((st & 1) && (st & (1 << M - 1)) && (st & (1 << M))) 
   //바로 왼쪽 칸이 1인지, 바로 위 칸이 1인지, 왼쪽 위칸이 1인지      
       return ret = sol(idx + 1, (st << 1) % m); 
    ret = sol(idx + 1, ((st << 1) | 1) % m);
//2x2가 안 채워진 경우, 다음 칸으로 이동하면서 st를 
//왼쪽으로 한 칸 밀고 현재 칸을 1로 채움 
    ret += sol(idx + 1, (st << 1) % m);
//2x2가 안 채워진 경우, 담 칸으로 이동하면서 st를 
//왼쪽으로 한 칸 밀고 현재 칸을 0으로 채움.
//배치의 모든 경우의 수를 찾아야하기에 ret에 그대로 더해줌.
//ret은 초기값이 -1이기에 위아래 sol을 각가 모두 ret에 +=로 해주면 안됨.
    ret %= mod; 
    return ret; 
} 

int main(void) { 
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    cin >> N >> M; 
    
    if (M > N) swap(N, M);//비트마스크 크기를 줄이기 위해
    //2x2만 없애주면 되기에 스왑해도 문제없음.
    m = 1 << M + 1;//M+1개의 비트만 사용하기 위해
     memset(dp, -1, sizeof(dp)); 
     cout << sol(0, 0); 
     return 0; 
    }