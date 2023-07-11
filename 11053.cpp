#include <iostream>
#include <vector>
#include <algorithm>
int dp[1001] = { 0, };
using namespace std;

int main() {
    int T,K;
    int answer = 0;
    vector<int> v;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> K;
        v.push_back(K);
        int dp_max = 0;

        for (int j = 0; j < v.size(); j++) {
            if (v[i] > v[j]) {
                if (dp_max < dp[j])
                    dp_max = dp[j];
            }
        }
        dp[i] = dp_max + 1;
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;
}