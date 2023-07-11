#include<iostream>

using namespace std;

int main () {
	int N, K, R, D;
	cin >> N >> K;
	R = 1;
	D = 1;
	while (K) {
		R *= N;
		D *= K;
		N--;
		K--;
		
	}
	cout << R / D;
	return 0;
}