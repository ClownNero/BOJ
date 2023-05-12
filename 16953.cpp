#include<iostream>
#include<queue>
using namespace std;
long long A, B;
void bfs() {
	queue<pair<long long,long long>> q;
	q.push({ A,0 });
	while (!q.empty()) {
		long long a = q.front().first;
		long long num = q.front().second;
		q.pop();
		if (a == B) {
			cout << num + 1;
			return;
		}
		if ((a * 2) <= B) {
			q.push({ a * 2, num + 1 });
		}
		if ( (a * 10 +1) <= B) {
			q.push({ a * 10 + 1 ,num + 1 });
		}
	}
	cout << -1;
}
int main() {
	cin >> A >> B;
	bfs();
}