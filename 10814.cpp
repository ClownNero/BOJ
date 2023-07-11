#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}
int main() {
    int num;
    cin >> num;
    pair<int, string> tmp;
    vector<pair<int, string>> arr;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }
    /*
    stable_sort()는 sort()와 비슷하지만 다른 정렬 도구다.
    첫 번째 원소가 같을 경우, 두 번째 원소의 입력 순서대로 출력을 보장한다. 
    즉 동일한 값에 대해 기존 순서가 보장되는, 예측할 수 있는 안정적인 정렬이다.
    */
    stable_sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < num; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
}