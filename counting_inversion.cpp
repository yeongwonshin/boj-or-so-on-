#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge_count(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    ll inv = 0;

    inv += merge_count(arr, left, mid);
    inv += merge_count(arr, mid + 1, right);

    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            inv += (mid - i + 1); // 핵심!
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];

    return inv;
}

int main() {
    vector<int> arr = {3,1,2};
    cout << merge_count(arr, 0, arr.size()-1);
}