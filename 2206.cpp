#include<iostream>
#include<queue>
#include<string>
using namespace std;
int map[1000][1000];
bool visited[1000][1000][2];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int N, M;

void bfs() {
	queue<pair<int, pair<int, pair<int, int>>>> q;
	q.push({ 1,{0,{0,0} } });
	visited[0][0][0] = true;
	while (q.empty() == 0) {
		int cnt = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second.first;
		int broken = q.front().second.second.second;
		q.pop();
		if (y == M - 1 && x == N - 1) {
			cout << cnt;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nextY = y + dy[i];
			int nextX = x + dy[i];
			if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < M) {
				if (map[nextX][nextY] == 1 && broken == 0)
				{
					visited[nextX][nextY][broken+1] = true;
					q.push({ cnt + 1,{nextY,{nextX,broken+1} } });
				}
				else if (map[nextX][nextY] == 0 && visited[nextX][nextY][broken] == false) {
					visited[nextX][nextY][broken] = true;
					q.push({ cnt + 1,{nextY,{nextX,broken} } });
				}

			}
		}
	}
	cout << "-1";
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