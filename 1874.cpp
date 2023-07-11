#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
	int N,NUM;
	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		cin >> NUM;
		q.push(NUM);
	}
	vector<int> r;
	int i = 1;
	while(q.size() >0){
		if (q.front() == r.back()) {
			cout << '+' << '\n';
			r.push_back(i);
			r.pop_back();
			q.pop();
			cout << '-' << '\n';
		}
		else {
			r.push_back(i);
			cout << '+' << '\n';
		}
		i++;
	}
}