#include <iostream>
#include <deque>
using namespace std;

#define MAX_SIZE 100000+1

int N, K;
int visited[MAX_SIZE];

void bfs() {
    deque<int> dq;
    dq.push_back(N);
    visited[N] = 1;
    while (!dq.empty()) {
        // ���� ���� ��ҵ���� ������
        int pos_x = dq.front();
        dq.pop_front();

        if (pos_x == K) {
            cout << (visited[K] - 1);
            return;
        }
        // �����̵��� ���� ���ʿ� �������.
        if (pos_x * 2 < MAX_SIZE && !visited[pos_x * 2]) {
            dq.push_front(pos_x * 2);
            visited[pos_x * 2] = visited[pos_x];
        }

        // �ȴ��̵��� ���� ���ʿ� �������.
        if (pos_x + 1 < MAX_SIZE && !visited[pos_x + 1]) {
            dq.push_back(pos_x + 1);
            visited[pos_x + 1] = visited[pos_x] + 1;
        }

        // �ȴ��̵��� ���� ���ʿ� �������.
        if (pos_x - 1 >= 0 && !visited[pos_x - 1]) {
            dq.push_back(pos_x - 1);
            visited[pos_x - 1] = visited[pos_x] + 1;
        }
    }
}

int main() {
    cin >> N >> K;
    bfs();
}