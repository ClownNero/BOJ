#include<iostream>
#include<deque>

using namespace std;

int main() {
	int N, M;
	string str;
	deque<int> dq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push_front") {
			cin >> M;
			dq.push_front(M);
		}
		else if (str == "push_back") {
			cin >> M;
			dq.push_back(M);
		}
		else if (str == "pop_front") {
			if (dq.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (str == "front") {
			if (dq.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << dq.front() << endl;
			}

		}
		else if (str == "back") {
			if (dq.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << dq.back() << endl;
			}
		}
		else if (str == "size") {
			cout << dq.size() << endl;
		}
		else if (str == "empty") {
			cout << dq.empty() << endl;
		}
	}
	return 0;
}