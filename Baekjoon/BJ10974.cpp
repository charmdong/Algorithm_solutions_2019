#include <iostream>
#include <vector>

using namespace std;

int n;
bool isUsed[9];
vector<int> list;

void dfs();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    dfs();

    return 0;
}

void dfs() {
    if(list.size() == n) {
        for(int index = 0; index < n; index++) {
            cout << list[index] << " ";
        }
        cout << "\n";
    }

    for(int index = 1; index <= n; index++) {
        if(!isUsed[index]) {
            isUsed[index] = true;
            list.push_back(index);
            dfs();
            list.pop_back();
            isUsed[index] = false;
        }
    }
}