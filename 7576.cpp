#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;
// 상 하 좌 우
int dx[4] = { -0, 0, -1, 1 };
int dy[4] = { -1, 1, -0, 0 };
int n, m, result =0;
int map[1000][1000];

queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >=0 && ny >=0 && nx < m && ny < n && map[ny][nx] == 0) {
				map[ny][nx] = map[y][x] + 1;
				q.push({ ny,nx });
			}
		}

	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);	cin.sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 0; i < n; i++) { // 세로 y
		for (int j = 0; j < m; j++) { // 가로 x
			int num;
			cin >> num;
			map[i][j] = num;
			if (num == 1) {
				q.push({ i,j });
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (result < map[i][j]) {
				result = map[i][j];
			}
		}
	}
	cout << result - 1 << '\n';

}