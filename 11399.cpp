#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, num,sum = 0;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int n=0;
	for (auto i : v) {
		n += i;
		sum += n;
	}
	cout << sum;
}