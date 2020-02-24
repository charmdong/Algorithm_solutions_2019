#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x, y, w, h;
    vector<int> v;

    cin >> x >> y >> w >> h;

    v.push_back(x);
    v.push_back(y);
    v.push_back(w - x);
    v.push_back(h - y);

    sort(v.begin(), v.end());

    cout << v[0] << endl;

    return 0;
}