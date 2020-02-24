
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer = 0;
vector<int> ary;
vector<int> maxList;

int function(int x, int y);

int main()
{
    cin >> n;

    ary.assign(n, 0);

    for(int index = 0; index < n; index++) {
        cin >> ary[index];
    }

    if(n == 1) {
        cout << ary[0] << endl;
        return 0;
    }

    sort(ary.begin(), ary.end());
    
    while(true) {
        int res = function(ary[0], ary[1]);

        for(int index = 2; index < n; index++) {
            res = function(res, ary[index]);
        }

        if (answer < res) {
            answer = res;
            maxList = ary;
        }

        if(!next_permutation(ary.begin(), ary.end())) {
            break;
        }
    }

    for(int t : maxList) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}

int function(int x, int y) {
    return (x | y) - y;
}