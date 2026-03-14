#include <bits/stdc++.h>
using namespace std;

struct Seg {
    double x1, y1, x2, y2;
};

double getY(const Seg &s, double x) {
    return s.y1 + (s.y2 - s.y1) * (x - s.x1) / (s.x2 - s.x1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<pair<double,double>> P(N);
    for(int i=0;i<N;i++) cin >> P[i].first >> P[i].second;

    vector<Seg> seg(M);
    for(int i=0;i<M;i++)
        cin >> seg[i].x1 >> seg[i].y1 >> seg[i].x2 >> seg[i].y2;

    for(int i=0;i<N;i++){
        double x = P[i].first;
        double y = P[i].second;
        int cnt = 0;

        while(true){
            int idx = -1;
            double bestY = -1e18;

            for(int j=0;j<M;j++){
                double lx = min(seg[j].x1, seg[j].x2);
                double rx = max(seg[j].x1, seg[j].x2);

                if(x < lx || x > rx) continue;

                double sy = getY(seg[j], x);

                if(sy < y && sy > bestY){
                    bestY = sy;
                    idx = j;
                }
            }

            if(idx == -1) break;

            cnt++;

            if(seg[idx].y1 < seg[idx].y2){
                x = seg[idx].x1;
                y = seg[idx].y1;
            } else {
                x = seg[idx].x2;
                y = seg[idx].y2;
            }
        }

        cout << cnt << "\n";
    }
}