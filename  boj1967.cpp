#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
typedef struct Node {
	vector<Node*> children = vector<Node*>();
	int weight;
};

Node nodes[10001];
int value = 0;
int traverse(Node *root) {
	//자식이 없는 경우 부모쪽으로 가는 간선의 값 return
	if (root->children.size() == 0) return root->weight;
	//자식이 하나일 경우 자신의 weight을 더해 return
	if (root->children.size() == 1) 
		return root->weight + traverse(root->children[0]);
	
	//여기서부터는 자식이 둘 이상
	vector<int> weights = vector<int>(root->children.size());

	//자식들 모두 다 돌때까지
	for (int i = 0; i < root->children.size(); i++) 
		weights[i] = traverse(root->children[i]);
	
	//오름차순으로 정렬
	sort(weights.begin(), weights.end());

	//가장 큰 값을 가진 두 값을 더해서 value와 비교하여 value업데이트
	value = max(weights[root->children.size()-1]
		+ weights[root->children.size()-2], value);
	
	//현재의 weight와 다 더한값의 제일큰 weights값을 더하여 return
	return root->weight+weights[root->children.size()-1];
}

int main() {
	
	scanf("%d", &n);
	nodes[1] = Node();
	nodes[1].weight = 0;
	n--;
	for (int i = 0; i < n; i++) {
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);
		nodes[to] = Node();
		nodes[to].weight = weight;
		nodes[from].children.push_back(&nodes[to]);
	}
	int ret = max(value, traverse(&nodes[1]));
	printf("%d\n", ret);
}