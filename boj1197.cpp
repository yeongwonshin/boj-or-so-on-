#include <bits/stdc++.h>
using namespace std;

//prim algorithm solution. 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V+1);

    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    vector<bool> visited(V+1,false);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    pq.push({0,1});

    long long ans = 0;

    while(!pq.empty()){
        auto [cost, node] = pq.top();
        pq.pop();

        if(visited[node]) continue;

        visited[node] = true;
        ans += cost;

        for(auto &[nextCost, nextNode] : adj[node]){
            if(!visited[nextNode]){
                pq.push({nextCost, nextNode});
            }
        }
    }

    cout << ans;
}