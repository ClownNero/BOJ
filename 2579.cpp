#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[301];
int main() {
	/*
	첫번째칸의 max은 무조건 첫번째칸 밟기
	두번째칸의 max은 첫번째+2번째 밟기
	세번째칸의 max는 (첫번째+세번째 )또는 (두번째+세번째)
	네번째는 (두번째까지의 최대외 네번째의 합) 또는 (첫번째까지의 최대와 바로직전인 세번째와 네번째의 합)
	*/
	int N,NUM;
	cin >> N;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		cin >> NUM;
		v.push_back(NUM);
	}
	dp[1] = v[0];
	dp[2] = v[0] + v[1];
	dp[3] = max(v[0] + v[2], v[1] + v[2]);
	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2] + v[i-1], dp[i-3] + v[i-2] + v[i-1]);
	}
	cout << dp[N];
}