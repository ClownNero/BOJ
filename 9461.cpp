#include<iostream>

using namespace std;
long long dp[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
	for (int i = 6; i < 101; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	int T, num;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num;
		cout << dp[num]<<'\n';
	}
}