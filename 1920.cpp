#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> v;
	int N, M, NUM;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> NUM;
		v.push_back(NUM);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> NUM;
		bool it = binary_search(v.begin(), v.end(), NUM);
		if (it == false) {
			cout << 0 << '\n';
		}
		else {
			cout << 1 << '\n';
		}
	}

	return 0;
}