#include<iostream>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	int n, m;
	map<string, string> account;
	map<string, string> reverse;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		string b = to_string(i);
		account[str] = b;
		reverse[b] = str;
	}
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		cout << account[a];
		cout << reverse[a];
		cout << '\n';
	}
}