/**
 * @author : donggun.chung
 * @date : 2020.02.10
 * @site : BOJ
 * @prob_Info : 1991 트리 순회 
 * @time : 
 * @memory : 
 */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<char> tree;

void solution();
void preorder(int current = 1);
void inorder(int current = 1);
void postorder(int current = 1);

int main()
{
    cin >> n;
    tree.assign(n + 1, 0);

    char p, left, right;
    for(int index = 1; index <= n; index++) {
        scanf(" %c %c %c", &p, &left, &right);
        tree[index] = p;
        tree[index * 2] = 
    }

    solution();

    return 0;
}

void solution() {
    preorder();
    cout << "\n";
    inorder();
    cout << "\n";
    postorder();
    cout << "\n";
}

void preorder(int current) {
    if(current > n || tree[current] == '.') {
        return;
    }
    
    cout << tree[current];
    preorder(current * 2);
    preorder(current * 2 + 1);
}

void inorder(int current) {
    if(current > n || tree[current] == '.') {
        return;
    }

    inorder(current * 2);
    cout << tree[current];
    inorder(current * 2 + 1);
}

void postorder(int current) {
    if(current > n || tree[current] == '.') {
        return;
    }

    postorder(current * 2);
    postorder(current * 2 + 1);
    cout << tree[current];
}