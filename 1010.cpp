#include<iostream>

using namespace std;
int T,N,M;
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		int ans = 1;
		int r = 1;
		for (int i = M; i > M - N; i--) {
			ans *= i;
			ans /= r++;
		}
		cout << ans << '\n';
	}
}