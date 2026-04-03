#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//아래는 구간 최대합 세그먼트 트리. 평범한 구간합 세그트리와 다름.
//빌드: O(N), 쿼리, 업데: O(logN)

struct Node {
    ll sum, lmax, rmax, tmax;
};
//lmax: 구간 왼쪽 끝에서부터의 최대합
/*ex.구간: [ 3, -2, 5, -1 ]
lmax = max(
  3,
  3 + (-2),
  3 + (-2) + 5,
  3 + (-2) + 5 + (-1)
) = 6 */
//rmax: 구간 오른쪽 끝에서부터의 최대합 
/*구간: [ 3, -2, 5, -1 ]
rmax = max(
  -1,
  5 + (-1),
  -2 + 5 + (-1),
  3 + (-2) + 5 + (-1)
) = 5
*/
//tmax: 구간 최대합, sum: 구간전체합,
/*구간: [ 3, -2, 5, -1 ]
tmax = 6   // 3 + (-2) + 5
*/ 
Node merge(Node a, Node b) {
    return {
        a.sum + b.sum,
        max(a.lmax, a.sum + b.lmax),
        max(b.rmax, b.sum + a.rmax),
        max({a.tmax, b.tmax, a.rmax + b.lmax})
        //3개부턴 {}로 묶어줘야함
    };
}

vector<ll> arr;
vector<Node> tree;

Node make_node(ll x) {
    return {x, x, x, x};//리프노드 생성을 위한 함수
}

void build(int node, int l, int r) {
    if (l == r) {//리프노드
        tree[node] = make_node(arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}

Node query(int node, int l, int r, int ql, int qr) {
  //node: 현재 노드 번호, l,r: 현재 노드가 담당하는 구간  
    if (qr < l || r < ql)
        return {0, LLONG_MIN, LLONG_MIN, LLONG_MIN};

    if (ql <= l && r <= qr)
        return tree[node];

    int mid = (l + r) / 2;
    if (qr <= mid) return query(node*2, l, mid, ql, qr);
    if (ql > mid) return query(node*2+1, mid+1, r, ql, qr);

    return merge(
        query(node*2, l, mid, ql, qr),
        query(node*2+1, mid+1, r, ql, qr)
    );
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    tree.resize(4 * n);
    build(1, 0, n - 1);

    Node res = query(1, 0, n - 1, 0, n - 1);
    cout << res.tmax << "\n";

    return 0;
}