#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//빌드: O(N), 쿼리, 업데: O(logN)
struct Node {
    ll sum, lmax, rmax, tmax;
};

Node merge(Node a, Node b) {
    return {
        a.sum + b.sum,
        max(a.lmax, a.sum + b.lmax),
        max(b.rmax, b.sum + a.rmax),
        max({a.tmax, b.tmax, a.rmax + b.lmax})
    };
}

vector<ll> arr;
vector<Node> tree;

Node make_node(ll x) {
    return {x, x, x, x};
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = make_node(arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}

Node query(int node, int l, int r, int ql, int qr) {
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