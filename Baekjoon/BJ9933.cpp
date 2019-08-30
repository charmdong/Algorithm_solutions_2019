#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, char> solution();

int main()
{
    pair<int, char> res = solution();
    cout << res.first << " " << res.second << endl;
    return 0;
}

pair<int, char> solution() {
    int n;
    vector<string> strList;    
    
    cin >> n;
    strList.assign(n, "");
    for(int i=0; i<n; i++) {
        cin >> strList[i];
    }
    
    for(int i = 0; i < n - 1; i++) {
        string tmp = strList[i];
        reverse(tmp.begin(), tmp.end());

        for(int j = i; j < n; j++) { // check myself
            if(strList[i].length() != strList[j].length()) {
                continue;
            }

            if(strList[j] == tmp) {
                return make_pair(tmp.length(), tmp[tmp.length() / 2]);
            }
        }
    }
}