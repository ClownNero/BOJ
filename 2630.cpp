#include<iostream>
#define MAX 128
using namespace std;
int map[MAX][MAX];
int w = 0, b = 0;
void solve(int y, int x, int size) {
	int check = map[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (check == 0 && map[i][j] == 1) {
				check = 2;
			}
			else if (check == 1 && map[i][j] == 0) {
				check = 2;
			}
			if (check == 2) {
				solve(y, x, size / 2);// 1사분면
				solve(y, x + size / 2, size / 2); // 2사분면
				solve(y + size / 2, x, size / 2); // 3사분면
				solve(y + size / 2, x + size / 2, size / 2); // 4사분면
				return;
			}
		}
	}
	if (check == 0) w++;
	else b++;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	bool ok = true;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve(0, 0, N);
	cout << w << '\n';
	cout << b << '\n';
	
	
}