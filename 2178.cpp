#include <iostream>
#include<string>
#include<queue>
using namespace std;

int n, m;
int graph[100][100];

// �̵��� �װ��� ���� (��, ��, ��, ��)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    // ť�� �� ������ �ݸ�
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // ���� ��ġ���� 4���� �������� Ȯ��
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // �̷� ������ ��� ��� ����
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            // �̵��� �� ���� ĭ�� ��� ����
            if (graph[nx][ny] == 0)
            {
                continue;
            }
            // ó�� �湮 & �̵� ����
            if (graph[nx][ny] == 1)
            {
                graph[nx][ny] = graph[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
    // ���� ������ �Ʒ������� �ִ� �Ÿ� ��ȯ
    return graph[n - 1][m - 1];
}

int main()
{
    // �Է� �ޱ�
    cin >> n >> m;
    string input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = input[j] - '0';
        }
    }

    // ���
    cout << bfs(0, 0) << endl;

    return 0;
}