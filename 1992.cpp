#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int N;
int paper[2188][2188];
string str;
void solve(int x, int y, int size) {
	
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++)
		{
			
			if (paper[i][j] != paper[x][y])
			{
				str += '(';
				// 1사분면
				solve(x, y, size / 2);
				// 2사분면
				solve(x, y + size / 2, size / 2);
				
				// 3사분면
				solve(x + size / 2, y, size / 2);
				// 4사분면
				solve(x + size/2, y + size / 2, size / 2);
				str += ')';
				return;
			}
			
		}
	}
	str += to_string(paper[x][y]);
	
	return;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			paper[i][j] = input[j] - '0';
		}
	}
			

	solve(0, 0, N);
	cout  <<str ;

}