#include<iostream>
#include<set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b, c;
	set<int> s;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		cin >> c;
		s.insert(c);
	}
	while (b--) {
		cin >> c;
		if (s.find(c) == s.end()) {
			a++;
		}
		else {
			a--;
		}
	}
	cout << a;
}