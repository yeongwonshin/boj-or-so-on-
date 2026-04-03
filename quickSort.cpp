void quick_sort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {

        while (arr[i] < pivot) i++;
        //피벗보다 작은 값은 이미 왼쪽그룹에 있어야하므로 통과
        //피벗보다 크거나 같은 값에서 멈춤
        while (arr[j] > pivot) j--;
//pivot보다 큰 값은 오른쪽 그룹에 있어야 하므로 통과
        if (i <= j) {//왼쪽에 큰 값, 오른쪽에 작은값이 발견된 상태
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
    //이거 순서 위아래 순서 바꿔도 됨.
}
/* 5 1 4 2 3이고 pivot이 4인 경우
i는 5에서 멈추고 j는 3에서 멈춤. i와 j가 가리키는 값이 서로 바뀌어야하므로 swap.
1단계 분할 후 3 1 2 | 4 5
왼쪽재귀 --> 3 1 2에서 pivot이 1인 경우
오른쪽 재귀 --> 4 5에서 pivot이 5인 경우
*/