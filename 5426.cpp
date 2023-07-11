#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int len = str.length();
		int N = sqrt(len);
		for (int i = N; i >=1; i--) {
			for (int j = 0; j < N; j++) {
				cout << str[i-1 + N*j];
			}
		}
		cout << '\n';
	}
}