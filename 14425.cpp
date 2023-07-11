#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	int sum = 0;
	int n, m;
	cin >> n >> m;
	map<string, int> account;
	for (int i = 0; i < n; i++) {
		cin >> str;
		account[str]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (account[str] > 0) {
			sum++;
		}
	}
	cout << sum << '\n';
}