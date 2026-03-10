#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int> pq; //max-heap으로 구현

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x;
            cin >> x;
            pq.push(x);
        }
    }

    // N-1번 제거
    for(int i = 0; i < N-1; i++)
        pq.pop();

    cout << pq.top() << "\n";

    return 0;
}
