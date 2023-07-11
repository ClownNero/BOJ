#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[1001][1001];
string a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	for (int i = 1; i <= b.length(); i++) {
		for (int j = 1; j <= a.length(); j++) {
			if (a[j - 1] == b[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int k = a.length();
	string result;
	for (int i = b.length(); i >= 0; i--) {
		if (dp[i][k] == 0) break;
		for (int j = k; j >= 0; j--) {
			if(dp[i][j] == dp[i - 1][j]) break;
			if (dp[i][j] != dp[i][j - 1]) {
				result += a[j - 1];
				k = j - 1;
				break;
			}
		}
	}
	cout << dp[b.length()][a.length()] << '\n';
	if (dp[b.length()][a.length()] == 0) return 0;
	for (int i = result.length() - 1; i >= 0; i--) {
		cout << result[i];
	}
	cout << '\n';
}