#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> s;
string str;
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else { // ')'
			if (str[i - 1] == '(') { // �������� ���
				s.pop();
				ans += s.size();
			}
			else { // ������ ���� ���
				s.pop();
				ans++;
			}
		}
	}
	cout << ans;
}