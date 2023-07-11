#include<iostream>
#include<queue>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, NUM;
	priority_queue<int,vector<int>,greater<int>> pq;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> NUM;
		pq.push(NUM);
	}
	while (pq.size()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}