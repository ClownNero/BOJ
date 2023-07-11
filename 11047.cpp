#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	int coin,sum =0;
	vector<int> v;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin;
		v.push_back(coin);
	}
	while (K) {
		if (K / v.back()) {
			sum += K / v.back();
			K -= v.back() * (K / v.back());
			v.pop_back();
		}
		else {
			v.pop_back();
		}
	}
	cout << sum;
}