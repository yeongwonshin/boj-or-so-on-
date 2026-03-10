#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b){ 
    //b를 비트마스크로 표현하여 a^b를 구하는 함수. O(logb)
    //a^13=a^8×a^4×a^1(n=13=1101(2))
  ll res=1;
   while(b){
       if(b&1)res=res*a%10;
       a=a*a%10;//a^2, a^4, a^8...을 구하는 과정
       b>>=1;
   }
    return res;
} 

int main(){
    int t; cin>>t;
    while(t--){
    ll a, b, res;
    cin>>a>>b;
    
    res=power(a, b)%10;
    if(res==0)cout<<10<<'\n';
    else cout<<res<<'\n';
        }
    return 0;    
}