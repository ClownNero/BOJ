#include<iostream>
// ºÐÇÒÁ¤º¹ °ÅµìÁ¦°ö ¹®Á¦
using namespace std;
long long A, B, C;
long long POW(int B) {
    if (B == 0) return 1;
    long long temp = POW(B / 2);
    temp = temp * temp % C;
    if (B % 2 == 0) return temp; //Â¦¼ö ÀÏ¶§
    else return temp * A % C; //È¦ ¼ö ÀÏ¶§

}

int main(void) {
    cin >> A >> B >> C;
    cout << POW(B);
}
