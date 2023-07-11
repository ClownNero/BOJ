#include<iostream>
#include<queue>

using namespace std;
int n;
int map[22][22];
int dx[4] = {0, 0 , -1, 1}; // �����¿�
int dy[4] = {-1, 1, 0, 0}; // �����¿�
int bx, by; // �Ʊ��� ��ǥ
int result = 0; // �Ѱɸ� �ð�
int ecount = 0; // ����� ���� Ƚ��
int sz = 2; // �Ʊ��� ũ��
bool stop = false; // ���� ����Ⱑ ���� ���
bool eat = false; // �� ������ ���� ���

void bfs(int a, int b, bool visit[][22], int shSize) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b},0 });
	visit[b][a] = true;
	int temp = 0; // �� ������ �Դµ� �ɸ� �ð�
	while (!q.empty()) {
		int x = q.front().first.first; // �� ��ǥ
		int y = q.front().first.second; // �� ��ǥ
		int cnt = q.front().second; // ���� �ð�
		// ���� ������ ���� �� ���� ������ �켱������ �Դ� ���� ���
		if (map[y][x] > 0 && map[y][x] < shSize && temp == cnt) {
			if ((by > y) || (by == y && bx > x)) {
				by = y; // ����⸦ ���� ��� ��ġ ����
				bx = x;
				continue;
			}
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; // �����̵�
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[ny][nx]) {
				if (map[ny][nx] <= shSize) { // �������ų� ���� �� �ִ� ���
					if (map[ny][nx] > 0 && map[ny][nx] < shSize && !eat) { // ����⸦ ���� �� �ִ� ���
						eat = true; // �Ѹ��� ����
						bx = nx; // ���� ��ġ�� ����⸦ �Ծ��� ��ġ��
						by = ny;
						temp = cnt + 1; // �� ���� �Դµ� �ɸ� �ð�
						result += temp; // �� �ð��� �߰�
					}
					else { // ����⸦ ���Դ� ���
						q.push({ {nx,ny},cnt + 1 });
						visit[ny][nx] = true;
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				by = i; // �Ʊ��� ���� ��ǥ
				bx = j;
				map[i][j] = 0;
			}
		}
	}

	while (!stop) {
		bool visit[22][22] = { 0, };
		bfs(bx, by, visit, sz); // �� ���� ���������� �̵�
		if (eat) { // ���� ���
			eat = false;
			ecount += 1; // ���� ũ�⿡�� ����� ���� Ƚ�� ����
			map[by][bx] = 0; //���� ����� ����
			if (ecount == sz) { // ��� ũ�Ⱑ �����ϴ� ���
				sz += 1; // ��� ������ +1
				ecount = 0; // ���� ũ�⿡�� ����� ���� Ƚ�� �ʱ�ȭ
			}
		}
		else { // �� ������ ������ ���
			stop = true; // ���� ���� ���� ��û�ؾ���.
		}
	}
	cout << result << '\n';
}
