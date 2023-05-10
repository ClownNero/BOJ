#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> pp;

int n;
char map[101][101];
int visit[101][101] = { 0, };

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

void init_visit() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}
}

int all_visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

int bfs() {

	int cnt = 0;

	pp p;
	int tx, ty;

	tx = ty = 0;

	while (!all_visit()) { //모두 방문할 때까지
		queue<pp> q;

		q.push({ tx, ty });
		visit[ty][tx] = 1;
		char c = map[ty][tx];

		while (!q.empty()) { //문자 c에 대한 bfs
			p = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				tx = p.first + dx[i];
				ty = p.second + dy[i];

				if (tx < 0 || tx >= n || ty < 0 || ty >= n)
					continue;
				if (visit[ty][tx] == 1)
					continue;
				if (map[ty][tx] != c)
					continue;

				visit[ty][tx] = 1;
				q.push({ tx, ty });
			}
		}

		for (int i = 0; i < n; i++) { //아직 방문하지 않은 문자 위치
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) {
					tx = j;
					ty = i;
				}
			}
		}

		cnt++;
	}

	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	int a = bfs();  //적록색약이 아닌 사람이 본 개수 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G') //G를 R로 변경
				map[i][j] = 'R';
		}
	}

	init_visit();
	int b = bfs();  //적록색약인 사람이 본 개수 

	cout << a << " " << b;

	return 0;
}