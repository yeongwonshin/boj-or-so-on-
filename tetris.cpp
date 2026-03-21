#include <bits/stdc++.h>
using namespace std;

int Blocks[7][4][4][4];

void rotate90(int src[4][4], int dst[4][4]) {
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            dst[j][3-i] = src[i][j];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int A;
    cin >> A;

    int field[12][8];

    for(int i=0;i<12;i++)
        for(int j=0;j<8;j++)
            cin >> field[i][j];

    int Block_in[7][4][4] =
    {
        {{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
        {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
        {{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0}},
        {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,0}},
        {{0,0,0,0},{0,0,0,0},{1,0,0,0},{1,1,1,0}},
        {{0,0,0,0},{0,0,0,0},{0,1,0,0},{1,1,1,0}},
        {{0,0,0,0},{0,0,0,0},{0,0,1,0},{1,1,1,0}}
    };

    for(int i=0;i<7;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                Blocks[i][0][j][k] = Block_in[i][j][k];

    for(int i=0;i<7;i++)
        for(int j=1;j<4;j++)
            rotate90(Blocks[i][j-1], Blocks[i][j]);

    int ans = 0;

    for(int b=0;b<7;b++){
        for(int r=0;r<4;r++){

            int board[12][8];
            memcpy(board, field, sizeof(board));
//각 경우를 독립적으로 시뮬 돌리기 위해 복사.

            int y = 0;

            while(true){

                bool collide = false;//충돌여부

                for(int i=0;i<4;i++){//블록 내부 탐색
                    for(int j=0;j<4;j++){
                        if(Blocks[b][r][i][j]){
                //블록이 있는 칸만 검사

                            int ny = y+i;
                            int nx = A+j;

                            if(ny>=12 || nx<0 || nx>=8 || board[ny][nx]){
                                collide = true;//board[ny][nx]: 이미 블록이 있는 경우
                            }
                        }
                    }
                }

                if(collide) break;
                y++;//충돌이 없으면 한 칸 아래로 이동
            }

            y--;

            int score = 0;

            for(int i=0;i<4;i++){//블록 설치
                for(int j=0;j<4;j++){

                    if(Blocks[b][r][i][j]){

                        int ny = y+i;
                        int nx = A+j;

                        if(ny+1==12 || board[ny+1][nx])
                            score+=30;

                        board[ny][nx]=1;
                    }
                }
            }

            int lines=0;

            for(int i=0;i<12;i++){//줄 삭제

                bool full=true;

                for(int j=0;j<8;j++)
                    if(board[i][j]==0) full=false;

                if(full){
                    lines++;

                    for(int k=i;k>0;k--)
                        for(int j=0;j<8;j++)
                            board[k][j]=board[k-1][j];

                    for(int j=0;j<8;j++)
                        board[0][j]=0;
                }
            }

            score += lines*lines*100;

            ans=max(ans,score);
        }
    }

    cout<<ans;
}