#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321

using namespace std;
vector<pair<int, int>> v[20001];
int dist[20001];
int V, E, S;

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, S));
    dist[S] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int ncost = cost + v[cur][i].second;
            if (dist[next] > ncost) {
                dist[next] = ncost;
                pq.push(make_pair(ncost, next));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	cin >> S;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	Dijkstra();
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}