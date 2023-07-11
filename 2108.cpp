#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, NUM;
	double SUM=0;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> NUM;
		SUM += NUM;
		v.push_back(NUM);
	}
	cout << (int)round(SUM / N)<<'\n';
	sort(v.begin(), v.end());
	cout << v[N / 2]<<'\n';
	// 셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
	vector<int> r(N, 1);
	for (int i = 0; i < N; i++) {
		int b = lower_bound(v.begin(), v.end(), v[i]) - v.begin();
		int c = upper_bound(v.begin(), v.end(), v[i]) - v.begin();
		for (int j = b; j < c; j++) {
			r[j] = c - b;
		}
		i += c- b -1;
	}
	int ans=0;
	int count=0;
	for (int i = 0; i < N; i++) {
		if (r[ans] < r[i]) {
			count = 1;
			ans = i;
			i += r[i] - 1;
		}
		else if (r[ans] == r[i]) {
			count++;
			if (count == 2) ans = i;
			i += r[i] - 1;
		}
	}
	cout << v[ans]<<'\n';
	cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
}