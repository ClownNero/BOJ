#include <iostream>
#include<algorithm>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX] = { 0, };
int visited[10001] = { 0, };
void dfs(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= 10000; i++) {
        if (visited[i]) {
            visited[i]--;
            arr[depth] = i;
            dfs(depth + 1);
            visited[i]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        visited[num]++;
    }
    dfs(0);
}