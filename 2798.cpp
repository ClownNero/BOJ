#include<iostream>
#include<algorithm>

using namespace std;

int main () {
	int N, M;
	int SUM=0;
	cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				if ((arr[i] + arr[j] + arr[k]) <= M) {
					SUM = max(SUM, arr[i] + arr[j] + arr[k]);
				}
			}
		}
	}
	cout << SUM;
	return 0;
}