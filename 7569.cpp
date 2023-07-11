#include<iostream>
#include<queue>
// 상하좌우
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int dh[2] = { 1,-1 };

using namespace std;
int map[100][100][100];
int M, N, H;
int result = 0;

queue<pair<pair<int,int>, int>> q;

void bfs() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int h = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N && map[ny][nx][h] == 0) {
				map[ny][nx][h] = map[y][x][h] + 1;
				q.push({ { ny, nx }, h });
			}
		}
		for (int i = 0; i < 2; i++) {
			int nh = h + dh[i];
			if (nh >= 0 && nh < H && map[y][x][nh] == 0) {
				map[y][x][nh] = map[y][x][h] + 1;
				q.push({ { y, x }, nh });
			}
		}

	}

}
int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) { // 높이 i
		for (int j = 0; j < N; j++) { // 세로 j
			for (int k = 0; k < M; k++) { // 가로 k
				cin >> map[j][k][i];
				if (map[j][k][i] == 1) q.push({ { j, k }, i });
			}
		}
	}
	bfs( );
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < H; k++) {
				if (map[i][j][k] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				if (result < map[i][j][k]) {
					result = map[i][j][k];
				}
			}
			
		}
	}
	cout << result - 1 << '\n';

}