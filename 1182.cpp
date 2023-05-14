#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, S;
int arr[20];
bool visited[20];
int cnt = 0;
void dfs(int idx, int sum) {
	
	if (sum == S) {
		cnt++;
	}
	for (int i = idx; i < N; i++) {
		if (visited[i]) {
			continue;
		}
		else {
			visited[i] = true;
			dfs(i, sum + arr[i]);
			visited[i] = false;
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	dfs(0, 0);
	if (S == 0) {
		cout << cnt - 1;
	}
	else {
		cout << cnt;
	}
	
}