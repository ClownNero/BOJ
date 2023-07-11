#include<iostream>
#include<algorithm>
int dp[1000001];

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*
		X가 3으로 나누어 떨어지면, 3으로 나눈다.
		X가 2로 나누어 떨어지면, 2로 나눈다.
		1을 뺀다.
	*/
	dp[1] = 0;
	for (int i = 2; i <= 1000001; i++) {
		dp[i] = dp[i - 1] + 1;
		if (!(i % 3)) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	int N;
	cin >> N;
	cout << dp[N];
}