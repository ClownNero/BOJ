#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N;
char P, L, R;
int parent[26][2];

void preorder(char root) // 전위순회
{
    if (root == '.') return;
    else
    {
        cout << root;
        preorder(parent[root - 'A'][0]);
        preorder(parent[root - 'A'][1]);
    }
}

void inorder(char root) // 중위순회
{
    if (root == '.') return;
    else
    {
        inorder(parent[root - 'A'][0]);
        cout << root;
        inorder(parent[root - 'A'][1]);
    }
}

void postorder(char root) // 후위순회
{
    if (root == '.') return;
    else
    {
        postorder(parent[root - 'A'][0]);
        postorder(parent[root - 'A'][1]);
        cout << root;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> P >> L >> R;
        parent[P - 'A'][0] = L;
        parent[P - 'A'][1] = R;
    }

    preorder('A');
    cout << '\n';

    inorder('A');
    cout << '\n';

    postorder('A');
    cout << '\n';
}