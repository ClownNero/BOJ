#include<iostream>

using namespace std;
int dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[1] = 1; dp[2] = 3;
	int N;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + (2 * dp[i - 2])) % 10007;
	}
	cout << dp[N];
}