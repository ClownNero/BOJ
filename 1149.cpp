#include<iostream>
#include<algorithm>
int home[1001][3] = { 0, };
using namespace std;
int n;
int main() {
	int cost[3];
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		// i��°�� �������϶� �ּ�
		home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[0];
		// i��°�� �ʷϻ��϶� �ּ�
		home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[1];
		// i��°�� �Ķ����϶� �ּ�
		home[i][2] = min(home[i - 1][1], home[i - 1][0]) + cost[2];
	}
	cout << min(home[n][2], min(home[n][0], home[n][1]));

}