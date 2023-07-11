#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, count = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        bool isGroupWord = true;
        bool alphabet[26] = { false };

        for (int j = 0; j < word.length(); j++) {
            int index = word[j] - 'a';
            if (alphabet[index] == false) {
                alphabet[index] = true;
            }
            else {
                if (word[j] != word[j - 1]) {
                    isGroupWord = false;
                    break;
                }
            }
        }

        if (isGroupWord == true) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}