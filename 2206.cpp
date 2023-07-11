#include<iostream>
#include<queue>
#include<string>
using namespace std;
int map[1001][1001];
bool visited[1001][1001][2];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int N, M;

void bfs() {
	queue<pair<int, pair<int, pair<int, bool>>>> q;
	q.push({ 1,{0,{0,false} } });
	visited[0][0][0] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second.first;
		bool broken = q.front().second.second.second;
		q.pop();
		if (y == N -1 && x == M -1) {
			cout << cnt;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if (nextX >= 0 && nextY >= 0 && nextX < M && nextY < N) {
				if (map[nextY][nextX] == 0 && visited[nextY][nextX][broken] == false) {
					visited[nextY][nextX][broken] = true;
					q.push({ cnt + 1,{nextY,{nextX,broken} } });
				}
				if (map[nextY][nextX] == 1 && broken == false)
				{	
					visited[nextY][nextX][!broken] = true;
					q.push({ cnt + 1,{nextY,{nextX,!broken} } });
				}
			}
		}
	}
	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string In;
		cin >> In;
		for (int j = 0; j < M; j++) {
			int Tmp = In[j] - '0';
			map[i][j] = Tmp;
		}
	}
	bfs();
}