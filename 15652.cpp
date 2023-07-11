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
		arr[depth] = i;
		dfs(depth + 1, i);
		
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	dfs(0,1);
}