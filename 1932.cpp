#include<iostream>

using namespace std;
int dp[501][501];
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int num;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num;
			dp[i][j] = max(dp[i - 1][j - 1],dp[i - 1][j])+ num;
		}
	}
	int result = dp[n][1];
	for (int i = 1; i <= n; i++) {
		if (result <= dp[n][i]) result = dp[n][i];
	}
	cout << result;
}