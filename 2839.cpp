#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 9999999
using namespace std;
// 그리드로 풀기
/* 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N,a,b;
	cin >> N;
	a = N / 5;
	while (1) {
		if (a < 0) {
			cout << -1;
			return 0;
		}
		if ((N - (5 * a)) % 3 == 0) {
			b = (N - (5 * a)) / 3;
			break;
		}
		a--;
	}
	cout << a + b;
	return 0;
}
*/
// DP로 풀기
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; // 목표치
	cin >> n;
	vector<int> dp(n + 1, MAX); // 최소 개수 메모이제이션

	dp[3] = 1;
	dp[5] = 1;

	// Bottom-up
	for (int i = 6; i <= n; i++) {
		dp[i] = min(dp[i - 5] + 1, dp[i - 3] + 1);
	}

	if (dp[n] >= MAX)
		cout << "-1\n";
	else
		cout << dp[n] << '\n';

	return 0;
}