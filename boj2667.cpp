#include <bits/stdc++.h>
using namespace std;

int n;
string arr[25];

bool visited[25][25];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int bfs(int x,int y){

    queue<pair<int,int>> q;

    q.push({x,y});

    visited[x][y]=true;

    int cnt=1;

    while(!q.empty()){

        auto cur=q.front();
        q.pop();

        for(int i=0;i<4;i++){

            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<n){

                if(!visited[nx][ny] && arr[nx][ny]=='1'){

                    visited[nx][ny]=true;

                    q.push({nx,ny});

                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main(){

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> result;

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            if(arr[i][j]=='1' && !visited[i][j]){

                result.push_back(bfs(i,j));
            }
        }
    }

    sort(result.begin(),result.end());

    cout<<result.size()<<'\n';

    for(int x:result)
        cout<<x<<'\n';
}