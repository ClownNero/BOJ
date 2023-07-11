#include <iostream>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX] = { 0, };
bool visited[10001] = { 0, };
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
            visited[i] = false;
            arr[depth] = i;
            dfs(depth + 1);
            visited[i] = true;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        visited[num] = true;
    }
    dfs(0);
}