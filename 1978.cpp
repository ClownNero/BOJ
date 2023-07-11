#include <iostream>
#include <math.h>
using namespace std;

bool primeNumber(int num) {
    float root = sqrt(num);
    if (num <= 1) {
        return false;
    }
    else if (num == 2 || num == 3) {
        return true;
    }
    else {
        for (int i = 2; i <= root; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

}

int main() {

    int num, inputNum, count = 0;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> inputNum;
        if (primeNumber(inputNum)) {
            count++;
        }
    }
    cout << count;
}