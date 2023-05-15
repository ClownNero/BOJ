#include<iostream>
#include<stack>

using namespace std;

int main () {
	int T,R=0;
	char c;
	string str;
	stack<char>s;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			s.push(str[j]);
		}
		for (int j = 0; j < str.length(); j++) {
			if (s.top() == ')') {
				R++;
				s.pop();
			}
			else {
				R--;
				if (R < 0) break;
				s.pop();
			}
		}
		if (R == 0) {
			cout << "YES" << '\n';
			R = 0;
		}
		else {
			cout << "NO" << '\n';
			R = 0;
		}
	}
	return 0;
}