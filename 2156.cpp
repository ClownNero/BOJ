#include<iostream>
#include<algorithm>
int dp[10001];
int drink[10001];
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> drink[i];
	}
	dp[1] = drink[1];
	dp[2] = drink[1] + drink[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 3] + drink[i - 1] + drink[i], dp[i - 2] + drink[i]));
	}
	cout << dp[n];
}