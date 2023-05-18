#include<iostream>
#include<queue>

using namespace std;

int main () {
	int N,M;
	string str;
	queue<int> q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> M;
			q.push(M);
		}
		else if (str == "pop") {
			if (q.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (str == "front") {
			if (q.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
			}
			
		}
		else if (str == "back") {
			if (q.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << q.back() << endl;
			}
		}
		else if (str == "size") {
			cout << q.size()<<endl;
		}
		else if (str == "empty") {
			cout << q.empty()<<endl;
		}
	}
	return 0;
}