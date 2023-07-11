#include<iostream>
#include<map>

using namespace std;

long long n;

map<long long, long long > v;

long long fib(long long n) {
	if (n == 0) return v[0];
	if (v[n]) return v[n];
	if (n % 2 == 0) {
		v[n] = ((fib(n / 2)) * ((fib(n / 2 + 1) + fib(n / 2 - 1))));
	}
	else {
		v[n] = (((fib((n + 1) / 2)) * (fib((n + 1) / 2))) + (((fib((n - 1) / 2)) * (fib((n - 1) / 2)))));
	}
	return v[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	v[0] = 0;
	v[1] = v[2] = 1;
	cout << fib(n);
}