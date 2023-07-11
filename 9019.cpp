#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<deque>
using namespace std;
bool visited[10002] = { 0, };

void bfs(int s, int e) {
	queue<pair<int, string>> q;
	q.push({ s,""});
	visited[s] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string order = q.front().second;
		q.pop();
		if (num == e) {
			cout << order << '\n';
			return;
		}
		else {
			// D 연산
			int D = (num * 2) % 10000;
			if (!visited[D]) {
				visited[D] = true;
				q.push({ D , order+"D"});
			}
			// S 연산
			int S = num - 1 < 0 ? 9999 : num - 1;
			if (!visited[S]) {
				visited[S] = true;
				q.push({ S, order + "S" });
			}
			// L 연산
			int Ln = (num % 1000) * 10 + (num / 1000);
			if (!visited[Ln]) {
				visited[Ln] = true;
				q.push({ Ln, order +"L"});
			}
			// R 연산
			int Rn = num / 10 + (num % 10) * 1000;
			if (!visited[Rn]) {
				visited[Rn] = true;
				q.push({ Rn, order +"R"});
			}
		}
		
	}
}
int t;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	//n의 네 자릿수를 d1, d2, d3, d4라고 하자(즉 n = ((d1 × 10 + d2) × 10 + d3) × 10 + d4라고 하자)
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		bfs(x, y);
		memset(visited, 0, sizeof(visited));
	}
}