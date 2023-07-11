#include<iostream>
#include<queue>
int map[101] = { 0, };
bool visited[101] = { 0, };
using namespace std;
int n, m;

void play(int a, int b) {
	queue<pair<int, int>>q;
	q.push({ a,b });
	while (!q.empty()) {
		int loc = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int nextloc = loc + i;
			if (nextloc == 100) {
				cout << cnt + 1;
				return;
			}
			else if (nextloc < 100) {
				if (map[nextloc]) {
					nextloc = map[nextloc];
				}
				if (!visited[nextloc]) {
					q.push({ nextloc,cnt + 1 });
					visited[nextloc] = true;
				}
			}
		}
	}
}
int main() {
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		map[x] = y;
	}
	for (int j = 0; j < m; j++) {
		cin >> x >> y;
		map[x] = y;
	}
	play(1, 0);

}