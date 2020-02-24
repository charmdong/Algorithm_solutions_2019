#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;
    v.assign(n, 0);

    for(int index = 0; index < n; index++) {
        cin >> v[index];
    }

    if(next_permutation(v.begin(), v.end())) {
        for(int num : v) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}