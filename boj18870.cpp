#include <bits/stdc++.h>
using namespace std;

int main(){
    
set<int> s;
int n;
cin >> n;
vector<int> v(n);

for(int i=0;i<n;i++){
    cin >> v[i];
    s.insert(v[i]);
}

unordered_map<int,int> mp;
int idx = 0;

for(int x : s){
    mp[x] = idx++;
}

for(int i=0;i<n;i++){
    cout << mp[v[i]] << " ";
}
return 0;}