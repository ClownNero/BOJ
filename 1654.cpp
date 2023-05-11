#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<long long int> tree;

int main() {

    cin >> n >> m;

    for (auto i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        tree.push_back(x);
    }

    long long int start = 1;
    long long int end = *max_element(tree.begin(), tree.end());
    long long int result = 0;

    while (start <= end) {
        int total = 0;
        long long int mid = (start + end) / 2;
        for (auto i = 0; i < n; i++) {
            if (tree[i] >= mid) total += tree[i] / mid;
        }
        if (total < m) {
            end = mid - 1;
        }
        else {
            result = mid;
            start = mid + 1;
        }
    }
    cout << result;
}