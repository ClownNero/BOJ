#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main () {
	int T,S,NUM;
	vector<int> v1;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> NUM;
		v1.push_back(NUM);
	}
	sort(v1.begin(), v1.end());
	vector<int> v2;
	cin >> S;
	for (int j = 0; j < S; j++) {
		cin >> NUM;
		v2.push_back(NUM);
	}
	for (int j = 0; j < S; j++) {
		int b = lower_bound(v1.begin(), v1.end(), v2[j]) - v1.begin();
		int c = upper_bound(v1.begin(), v1.end(), v2[j]) - v1.begin();
		cout << c - b << ' ';
	}
	
	return 0;
}