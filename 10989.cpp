#include<iostream>
using namespace std;
int arr[10001];
int main() {
    int N, input;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input;
        arr[input]++;
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0)continue;
        else {
            for (int j = 0; j < arr[i]; j++) {
                cout << i << endl;
            }
        }
    }


    return 0;
}