#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, k;
bool first = true; // ó������ ��ġ�� ������
int visit[100003] = { 0 };
int result = 100003;
int result2 = 0;
void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b)); // a: ������ġ b: �ð�
    visit[a] = true; // ������ġ �湮 ó��

    while (!q.empty()) { // ť�� �� ������
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        visit[x] = true; // pop �� �湮 ó�� 
        if (!first && result < cnt) {
            break;
        }
        if (!first && result == cnt && x == k) {
            // ù ��İ� �ٸ� ������� ������ ���
            // ��ġ�� ����, �ɸ� �ð��� ������
            result2++; // ī��Ʈ
        }
        if (first && x == k) { //ó������ ��ġ�� �����ϰ� ���� ��
            result = cnt; // �ּ� �ð� ����
            first = false; // ó�� �湮 ���� false��
            result2++; // ī��Ʈ
        }

        if (x + 1 < 100001 && x + 1 >= 0 && !visit[x + 1]) {
            // �ȱ� +1
            // ���� üũ �� ���� ���� �湮 �� ������ Ȯ��
            q.push(make_pair(x + 1, cnt + 1));
        }
        if (x - 1 < 100001 && x - 1 >= 0 && !visit[x - 1]) {
            // �ȱ� -1
            q.push(make_pair(x - 1, cnt + 1));
        }
        if (x * 2 < 100001 && x * 2 >= 0 && !visit[x * 2]) {
            // �����̵� *2
            q.push(make_pair(x * 2, cnt + 1));
        }
    }
}
int main() {
    cin >> n >> k;

    bfs(n, 0);
    cout << result << endl; // �ɸ��� �ּ� �ð�
    cout << result2 << endl; // ��� ����
}
