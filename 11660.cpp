// 내가 푼 방식
#include<iostream>
#define MAX 1025
using namespace std;
int map[MAX][MAX] = { 0, };
int N, M, NUM;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> NUM;
			map[i][j] = map[i][j-1]+NUM;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		int ans = 0;
		cin >> a >> b >> c >> d;
		for (int j = a; j <= c; j++) {
			ans += map[j][d] - map[j][b - 1];
		}
		cout << ans << '\n';
	}

}
// DP로 풀었을 시
/*
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1025

int dp[MAX][MAX];
int N, M, ans;
int x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x1, x2, y1, y2;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> x;

			if (i == 1 && j == 1) dp[i][j] = x;
			else if (i == 1)
			{
				dp[i][j] = x + dp[i][j - 1];
			}
			else if (j == 1)
			{
				dp[i][j] = x + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = x + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]; // 겹치는 부분 빼기
			}
		}
			

	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]; // 겹치는 부분 더하기
		cout << ans << '\n';
	}
	
}
*/