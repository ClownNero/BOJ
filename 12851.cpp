#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, k;
bool first = true; // 처음으로 위치가 같은지
int visit[100003] = { 0 };
int result = 100003;
int result2 = 0;
void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b)); // a: 수빈위치 b: 시간
    visit[a] = true; // 수빈위치 방문 처리

    while (!q.empty()) { // 큐가 빌 때까지
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        visit[x] = true; // pop 후 방문 처리 
        if (!first && result < cnt) {
            break;
        }
        if (!first && result == cnt && x == k) {
            // 첫 방식과 다른 방식으로 도달한 방법
            // 위치가 같고, 걸린 시간도 같은지
            result2++; // 카운트
        }
        if (first && x == k) { //처음으로 위치가 동생하고 같을 때
            result = cnt; // 최소 시간 저장
            first = false; // 처음 방문 여부 false로
            result2++; // 카운트
        }

        if (x + 1 < 100001 && x + 1 >= 0 && !visit[x + 1]) {
            // 걷기 +1
            // 범위 체크 후 다음 점이 방문 된 점인지 확인
            q.push(make_pair(x + 1, cnt + 1));
        }
        if (x - 1 < 100001 && x - 1 >= 0 && !visit[x - 1]) {
            // 걷기 -1
            q.push(make_pair(x - 1, cnt + 1));
        }
        if (x * 2 < 100001 && x * 2 >= 0 && !visit[x * 2]) {
            // 순간이동 *2
            q.push(make_pair(x * 2, cnt + 1));
        }
    }
}
int main() {
    cin >> n >> k;

    bfs(n, 0);
    cout << result << endl; // 걸리는 최소 시간
    cout << result2 << endl; // 방법 개수
}
