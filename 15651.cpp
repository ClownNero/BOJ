#include<iostream>
#define MAX 8
using namespace std;
int n,m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
			arr[depth] = i;
			dfs(depth + 1);
	}

}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	dfs(0);
}