#include<iostream>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };
void dfs(int depth, int num) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[depth] = i;
			dfs(depth + 1, i+1);
			visited[i] = false;
		}
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	dfs(0, 1);
}