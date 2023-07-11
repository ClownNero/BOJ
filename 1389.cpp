#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int edge[101][101];
int N, M;
vector<pair<int,int>> v;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}
void bfs(int k) {
	queue<pair<int,int>>q;
	bool visited[101] = { 0, };
	int sum = 0;
	visited[k] = true;
	q.push({ k, 1 });
	while (!q.empty()) {
		int num = q.front().first;
		int count = q.front().second;
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (edge[num][i] && !visited[i]) {
				visited[i] = true;
				q.push({ i ,count + 1 });
				sum += count;
			}
		}
	}
	v.push_back({ k,sum });
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);	cin.sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		bfs(i);
	}
	sort(v.begin(), v.end(),cmp);
	cout << v[0].first;
}