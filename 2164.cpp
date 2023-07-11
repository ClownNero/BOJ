#include<iostream>
#include<queue>

using namespace std;

int main () {
	int N;
	queue<int> q;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (1) {
		q.pop();
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
		q.push(q.front());
		q.pop();
	}
	return 0;
}