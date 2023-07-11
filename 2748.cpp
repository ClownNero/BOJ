#include<iostream>

using namespace std;
long long dp[91];
int n;

long long fib(int n) {
	if (n == 0) return dp[0];
	if (dp[n]) return dp[n];
	dp[n] = fib(n - 1) + fib(n - 2);
	return dp[n];
}
int main() {
	cin >> n;
	dp[0] = 0;
	dp[1] = dp[2] = 1;
	cout << fib(n);
}