#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100][100];
bool visited[100][100];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs(int x,int y,int h){

    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;

    while(!q.empty()){

        auto [cx,cy]=q.front();
        q.pop();

        for(int i=0;i<4;i++){

            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<n){

                if(!visited[nx][ny] && arr[nx][ny]>h){

                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
}

int main(){

    cin>>n;

    int maxh=0;

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){

        cin>>arr[i][j];
        maxh=max(maxh,arr[i][j]);
    }

    int result=0;

    for(int h=0;h<=maxh;h++){

        memset(visited,false,sizeof(visited));

        int cnt=0;

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){

            if(!visited[i][j] && arr[i][j]>h){

                bfs(i,j,h);
                cnt++;
            }
        }

        result=max(result,cnt);
    }

    cout<<result;
}