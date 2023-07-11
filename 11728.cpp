#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> v;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N + M; i++) {
		cout << v[i] << ' ';
	}

}