#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {
	int T;
	cin >> T;
	pair<int, int> tmp;
	vector<pair<int, int>> v;
	for (int i = 0; i < T; i++) {
		cin >> tmp.first >> tmp.second;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < T; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}