#include<iostream>
#include<map>
#define mod 1000000

using namespace std;

long long n;

map<long long, long long > v;

long long fib(long long n) {
	if (n == 0) return v[0];
	if (v[n]) return v[n];
	if (n % 2 == 0) { // n이 짝수일 경우
		v[n] = ((fib(n / 2) % mod) * ((fib(n / 2 + 1) % mod + fib(n / 2 - 1) % mod) % mod)) % mod;
	}
	else { // n이 홀수일 경우
		v[n] = (((fib((n + 1) / 2) % mod) * (fib((n + 1) / 2) % mod) % mod) + (((fib((n - 1) / 2) % mod) * (fib((n - 1) / 2) % mod)) % mod)) % mod;
	}
	return v[n];
}
int main() {

	cin >> n;
	v[0] = 0;
	v[1] = v[2] = 1;
	cout << fib(n) << '\n';
}