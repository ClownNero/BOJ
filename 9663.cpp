#include<iostream>
#define MAX 15
using namespace std;
int n;
int sum =0;
int col[MAX];
bool check(int level) {
	for (int i = 0; i < level; i++) {
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i) {
			return false;
		}
	}
	return true;
}
void Queen(int start) {
	if (start == n) {
		sum++;
	}
	else {
		for (int i = 0; i < n; i++) {
			col[start] = i;
			if (check(start)) {
				Queen(start + 1);
			}
		}
	}
}

int main() {
	cin >> n;
	Queen(0);
	cout << sum;
}