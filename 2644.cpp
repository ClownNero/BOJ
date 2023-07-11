#include<iostream>
#include<vector>
using namespace std;
vector<int> tree[101];
bool visited[101];
int n,u,v;
int a, b, c;
int ans = -1;
void DFS(int x, int depth) {
	if (x == b) {
		ans =depth;
		return;
	}
	visited[x] = true;
	for (int i = 0; i < tree[x].size(); i++) {
		int next_node = tree[x][i];
		if (!visited[next_node]) {
			visited[next_node] = true;
			DFS(next_node, depth+1);
			visited[next_node] = false;
		}
	}
}
int main() {
	cin >> n;
	cin >> a >> b >> c;
	for (int i = 0; i < c; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	DFS(a, 0);
	cout << ans;
}