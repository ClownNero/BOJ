#include<iostream>
#include<cmath>
using namespace std;

int N;
int paper[2188][2188];
int ans[3];
int check;

void solve(int x, int y, int size) {

	check = paper[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++)
		{
			if (paper[i][j] != paper[x][y])
			{
				// 정사각형 9분할
				solve(x, y, size / 3);
				solve(x + size * 1 / 3, y, size / 3);
				solve(x + size * 2 / 3, y, size / 3);
				solve(x, y + size * 1 / 3, size / 3);
				solve(x + size * 1 / 3, y + size * 1 / 3, size / 3);
				solve(x + size * 2 / 3, y + size * 1 / 3, size / 3);
				solve(x, y + size * 2 / 3, size / 3);
				solve(x + size * 1 / 3, y + size * 2 / 3, size / 3);
				solve(x + size * 2 / 3, y + size * 2 / 3, size / 3);
				return;
			}
		}
	}
	ans[paper[x][y] + 1]++;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	solve(0, 0, N);

	for (int i = 0; i < 3; i++) cout << ans[i] << endl;

}