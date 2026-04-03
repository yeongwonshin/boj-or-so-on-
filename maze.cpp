#include <bits/stdc++.h>
using namespace std;
//bfs 4번으로 O(RC)
int R,C;
vector<string> maze;
vector<vector<int>> adj;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int id(int r,int c){//좌표를 1차원 정점 번호로 변환
    return r*C+c;
}
/*(0,0) → 0
(0,1) → 1
(0,2) → 2
(1,0) → 3
(1,1) → 4
*/
bool canMove(int r,int c,int dir){
    int mr=2*r+1;
    int mc=2*c+1;

    if(dir==0) return maze[mr-1][mc]==' ';
    if(dir==1) return maze[mr+1][mc]==' ';
    if(dir==2) return maze[mr][mc-1]==' ';
    if(dir==3) return maze[mr][mc+1]==' ';
    return false;
}

int bfs(int sr,int sc){

    vector<int> dist(R*C,-1);
    queue<int> q;

    int start=id(sr,sc);
    dist[start]=0;
    q.push(start);

    int ans=0;

    while(!q.empty()){
        int v=q.front(); q.pop();

        int r=v/C;
        int c=v%C;

        ans=max(ans,dist[v]);

        for(int d=0;d<4;d++){
            if(!canMove(r,c,d)) continue;

            int nr=r+dx[d];
            int nc=c+dy[d];

            if(nr<0||nr>=R||nc<0||nc>=C) continue;

            int nid=id(nr,nc);

            if(dist[nid]==-1){
                dist[nid]=dist[v]+1;
                q.push(nid);
            }
        }
    }

    return ans;
}

int main(){

    cin>>R>>C;
    cin.ignore();

    maze.resize(2*R+1);

    for(int i=0;i<2*R+1;i++)
        getline(cin,maze[i]);

    int ans=0;

    ans=max(ans,bfs(0,0));
    ans=max(ans,bfs(0,C-1));
    ans=max(ans,bfs(R-1,0));
    ans=max(ans,bfs(R-1,C-1));

    cout<<ans;
}