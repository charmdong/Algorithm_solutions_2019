#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(8, 0);

string solution();

int main()
{
    for(int index = 0; index < 8; index++) {
        cin >> v[index];
    }

    cout << solution();

    return 0;
}

string solution() {
    string answer = "";
    
    vector<int> asc = v;
    vector<int> des = v;

    sort(asc.begin(), asc.end());
    sort(des.rbegin(), des.rend());

    if(v == asc) {
        answer = "ascending";
    } else if(v == des) {
        answer = "descending";
    } else {
        answer = "mixed";
    }

    return answer;
}