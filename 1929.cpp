#include <iostream>
#include <math.h>
#include<vector>
using namespace std;
int primeNumber(int num) {
    float root = sqrt(num);
    if (num <= 1) {
        return false;
    }
    else if (num == 2 || num == 3) {
        return num;
    }
    else {
        for (int i = 2; i <= root; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return num;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> v;
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (primeNumber(i)) {
            v.push_back(i);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}