#include <iostream>
using namespace std;

int main() {
    int a, b, v;
    cin >> a >> b >> v;
    int days = 1;
    int height = 0;
    while (true) {
        height += a;
        if (height >= v) {
            break;
        }
        height -= b;
        days++;
    }
    cout << days << endl;
    return 0;
}
