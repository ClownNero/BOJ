#include<iostream>

using namespace std;
int dp[1001];
int N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
		for (int j = 1; j < i/2+1; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[N];
}