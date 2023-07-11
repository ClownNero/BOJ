#include<iostream>
#include<algorithm>
#include<vector>
int dp[1000001];
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, NUM;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> NUM;
		dp[i] = NUM + dp[i - 1];
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a-1] << '\n';
	}
}