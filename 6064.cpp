#include <iostream>
using namespace std;

int gcd(int a, int b) { // �ִ� �����
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { // �ּ� �����
    return (a * b) / gcd(a, b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int m, n, x, y;
        int result = -1;
        cin >> m >> n >> x >> y;
        int maxi = lcm(m, n); // �����
        for (int i = x; i <= maxi; i += m) { // m�� ���� => �������� �׻� x
            int ny = i % n; // y��
            if (ny == 0) // �̶��� y�� �ִ밪�� ��
                ny = n;

            if (ny == y) { // ����
                result = i;
                break;
            }
        }
        cout << result << '\n';
    }
    return 0;
}
