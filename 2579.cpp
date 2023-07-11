#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[301];
int main() {
	/*
	ù��°ĭ�� max�� ������ ù��°ĭ ���
	�ι�°ĭ�� max�� ù��°+2��° ���
	����°ĭ�� max�� (ù��°+����° )�Ǵ� (�ι�°+����°)
	�׹�°�� (�ι�°������ �ִ�� �׹�°�� ��) �Ǵ� (ù��°������ �ִ�� �ٷ������� ����°�� �׹�°�� ��)
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