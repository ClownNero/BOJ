#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T,NUM, SUM=0;
	cin >> T;
	stack<int> s;
	for (int i = 0; i < T; i++) {
		cin >> NUM;
		if (NUM == 0) {
			if (s.size() > 0) {
				SUM -= s.top();
				s.pop();
			}
			else continue;
		}
		else {
			SUM += NUM;
			s.push(NUM);
		}
	}
	cout << SUM;

}