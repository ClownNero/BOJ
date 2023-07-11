#include<iostream>
#include<algorithm>

using namespace std;
int T,n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int map[100002][2] = { 0, };
		int num;
		int result=0;
		for (int j = 0; j < 2; j++) {
			for (int k = 2; k < n + 2; k++) {
				cin >> map[k][j];
			}
		}
		for (int k = 2; k < n + 2; k++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0) {
					map[k][j] = max(map[k - 1][1], max(map[k - 2][0], map[k - 2][1])) + map[k][j];
				}
				else {
					map[k][j] = max(map[k - 1][0], max(map[k - 2][0], map[k - 2][1]))+ map[k][j];
				}
			}
			result = max(map[k][1],max( result,map[k][0]));
		}
		cout << result <<'\n';
	}	
}