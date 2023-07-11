#include <iostream>
#include <queue>
#define MAX 50

using namespace std;

// ���߹� ũ�� 
int r, c;

// ���߹�
int cabbage_field[MAX][MAX];

// � ���߿� ������ ���ߵ��� Ž���� BFS �Լ�
void BFS(int in_x, int in_y) {

    // � ���߿� ������ ���� ��ġ�� ���� Queue
    queue<pair<int, int>> adj_queue;

    // �����¿� Ž�� �� �����, ���� �迭
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    // �Է� ���� ������ ��ġ�� adj_queue �� ����
    adj_queue.push(make_pair(in_x, in_y));

    // �ش� ���ߴ� �湮�� ��ġ�� ����
    cabbage_field[in_x][in_y] = 0;

    // adj queue �� �ִ� ������ ��ġ�� ���� Ž���� ������
    while (!adj_queue.empty()) {

        // adj_queue �� front �� ��ġ�� ������ ��ġ ����
        int x = adj_queue.front().first;
        int y = adj_queue.front().second;

        // adj_queue �� front �� ��ġ�� ���� ����
        adj_queue.pop();

        // �ش� ���߿� �����¿�� ������ ���ߵ��� ��� Ž�� ��, adj queue �� ����
        for (int i = 0; i < 4; ++i) {

            // Ž���� ���� ��ġ
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            // �ش� ��ġ�� ���߹� ���ο� �ִ��� Ȯ��
            if (0 <= new_x && new_x < r && 0 <= new_y && new_y < c) {
                // �ش� ��ġ�� ���߰� �ִٸ�
                if (cabbage_field[new_x][new_y] == 1) {
                    // �ش� ���ߴ� �湮�� ��ġ�� ����
                    cabbage_field[new_x][new_y] = 0;
                    // adj queue �� �ش� ���� ��ġ�� ����
                    adj_queue.push(make_pair(new_x, new_y));
                }
            }
        }
    }
}
int main() {

    // �׽�Ʈ ���̽� ����
    int testcase;

    // ���� ��ġ
    int x, y;

    // ���� ����
    int cabbage_count;

    // �׽�Ʈ ���̽� ����
    cin >> testcase;

    // �׽�Ʈ ���̽� ������ŭ �ݺ�
    for (int t = 0; t < testcase; ++t) {

        // ���߹� ũ��, ���� ����
        cin >> r >> c >> cabbage_count;

        // ���� ��ġ �Է�
        for (int i = 0; i < cabbage_count; ++i) {
            cin >> x >> y;
            cabbage_field[x][y] = 1;
        }

        // ������������ ���� �ʱ�ȭ
        int worm = 0;

        // ���߹��� Ž���ϸ�, ������������ ���� �ľ�
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (cabbage_field[i][j] == 1) {
                    BFS(i, j);
                    worm++;
                }
            }
        }

        // ������������ ���� ���
        cout << worm << endl;
    }
}