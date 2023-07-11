#include<iostream>
#include<stack>

using namespace std;

int main () {
	stack<int> s;
	int N,NUM;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> NUM;
			s.push(NUM);
		}
		else if (str == "pop") {
			if (s.size() == 0) {
				cout << -1 << '\n';
			}
			else {
				
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (str == "size") {
			cout << s.size() << '\n';
		}
		else if (str == "empty") {
			cout << s.empty() << '\n';
		}
		else if (str == "top") {
			if (s.size() == 0) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
			}
		}
	}
	return 0;
}