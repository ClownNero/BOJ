#include<iostream>
#include<queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pair<int, int> tmp;
	int N, NUM;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> NUM;
		if (NUM == 0) {
			if (pq.size() == 0) cout << 0 << '\n';
			else {
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else {
			tmp.first = abs(NUM); tmp.second = NUM;
			pq.push(tmp);
		}
	}
}