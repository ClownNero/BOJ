#include<iostream>
#include<cmath>
using namespace std;
bool NUM[10] = { 0, };

int check(int n) {
	if (n == 0) {
		if (NUM[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (n > 0) {
		if (NUM[n % 10]) return 0;
		n /= 10;
		len++;
	}
	return len;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, num;
	int count = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		NUM[num] = true;
	}
	count = N - 100;
	if (count < 0) count = -count;
	for (int i = 0; i <= 1000000; i++) {
		int chanel = i;
		int len = check(chanel);
		if (len > 0) {
			int press = abs(chanel - N);
			if (count > press + len) {
				count = press + len;
			}
		}
	}
	cout << count;
}