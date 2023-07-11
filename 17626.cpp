#include<iostream>
#include<cmath>
using namespace std;
int dp[50001];
int main() {
    
    int n, value;
    int i = 0;
    cin >> n;
    while (n != 0) {
        value = sqrt(n);
        value = (int)value;
        n = n - pow(value, 2);
        i++;
    }
    cout << i;
    return 0;
}