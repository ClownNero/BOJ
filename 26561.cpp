#include<iostream>

using namespace std;

int main() {
	int T, p, t;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> p >> t;
		int a, b;
		a = t / 7;
		b = t / 4;
		cout << p - a + b << '\n';
	}
}