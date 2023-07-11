#include<iostream>
#include<queue>
using namespace std;

int main () {
	queue<int> q;
	queue<int> r;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		if (q.size() != 1) {
			for (int i = 0; i < K - 1; i++) {
				q.push(q.front());
				q.pop();
			}
			r.push(q.front());
			q.pop();
			continue;
		}
		else {
			r.push(q.front());
			q.pop();
		}
	}
	if (r.size() == 1) {
		cout << "<" << r.front() << ">";

	}
	else {
		cout << "<" << r.front() << ",";
		r.pop();
		while (!r.empty()) {
			if (r.size() == 1) {
				cout << " " << r.front() << ">";
				r.pop();
				continue;
			}
			cout << " " << r.front() << ",";
			r.pop();
		}
	}
	
	return 0;
}/* ������ �� ���� �ڵ�
 #include<iostream>
#include<queue>
using namespace std;

int N, K;
queue<int> q;

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) q.push(i);

	cout << "<";

	while (q.size() != 0)
	{
		for (int i = 1; i < K; i++)
		{
			q.push(q.front()); // i��° ī�带 �ǵڷ�
			q.pop();
		}
		cout << q.front();
		if (q.size() != 1) cout << ", ";
		q.pop();
	}
	cout << ">";

}
 */