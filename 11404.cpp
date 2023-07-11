#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
int road[101][101];
int n, m;
int s, e, cost;
int main() {
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) road[i][j] = 0;
			else road[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> cost;
		road[s][e] = min(road[s][e], cost);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (road[i][j] == INF) {
				cout << 0 << ' ';
				continue;
			}
			cout << road[i][j] << ' ';
		}
		cout << '\n';
	}
}