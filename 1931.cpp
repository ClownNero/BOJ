#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		pair<int, int> tmp;
		int start, end;
		cin >> start >> end;
		tmp.first = end;
		tmp.second = start;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	int time = v[0].first;
	int count = 1;

	for (int i = 1; i < N; i++) {
		if (time <= v[i].second) {
			count++;
			time = v[i].first;
		}
	}
	cout << count;
}