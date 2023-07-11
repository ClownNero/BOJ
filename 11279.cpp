#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int> pq;
	int N, NUM;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> NUM;
		if (NUM == 0) {
			if (pq.size() == 0) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(NUM);
	}
}