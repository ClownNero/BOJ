#include<iostream>

using namespace std;
int N;
int road[101][101];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> road[i][j];
			// 방향 그래프
		}
	}
	// 폴로이드 와샬 알고리즘
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (road[i][k] && road[k][j]) {
					road[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << road[i][j]<< " ";
			// 방향 그래프
		}
		cout << '\n';
	}
}