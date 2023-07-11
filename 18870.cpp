#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, NUM;
	vector<int> v; 
	map<int, int> m;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> NUM;
		v.push_back(NUM);
		m[NUM] = 0;
	}
	for (auto &at : m) {
		at.second = count;
		count++;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << m[v[i]] << ' ';
	}
}