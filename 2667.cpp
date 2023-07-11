#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int n, cnt =0;
int map[25][25];
bool visited[25][25] = { 0, };
// 이동할 네가지 방향(상,하,좌,우)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<int> result;
void bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;
	cnt++;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// 현재 위치에서 4가지 방향으로 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && 0 <= ny && nx < n && ny < n && visited[nx][ny] == false && map[nx][ny] == 1) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}
}
int main() {
	cin >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < n; j++) {
			map[i][j] = input[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				cnt = 0;
				bfs(i, j);
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
}