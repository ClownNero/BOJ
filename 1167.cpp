#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<pair<int, int>> graph[100001];
bool visit[100001];
int n, u, v, num;
int node, ans;
void DFS(int x, int dist) {
	visit[x] = true;
	if (dist > ans) {
		ans = dist;
		node = x;
	}
	for (int i = 0; i < graph[x].size(); i++) {
		int next_node = graph[x][i].first;
		int next_dist = graph[x][i].second + dist;
		if (!visit[next_node]) {
			visit[next_node] = true;
			DFS(next_node, next_dist);
			visit[next_node] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		while (1) {
			cin >> u;
			if (u == -1) break;
			cin >> v;
			graph[num].push_back({ u, v });
		}
	}
	DFS(1, 0);
	ans = 0;
	for (int i = 1; i <= n; i++) {
		visit[i] = false;
	}
	DFS(node, 0);
	cout << ans << '\n';
}