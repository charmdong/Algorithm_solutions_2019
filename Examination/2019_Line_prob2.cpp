#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> resultList;
vector<bool> visited;
string solution(vector<char> numList, int k);
void dfs(int index, string result, vector<char> numList);

int main()
{
    string numStr;
    int k;
    vector<char> numList;
    getline(cin, numStr);
    cin >> k;

    for(int i=0; i<numStr.length(); i++) {
        if (numStr[i] != ' ') {
            numList.push_back(numStr[i]);
        }
    }

    cout << solution(numList, k) << endl;

    return 0;
}

string solution(vector<char> numList, int k) {
    string result = "";

    visited.assign(numList.size(), false);
    sort(numList.begin(), numList.end());
    dfs(0, result, numList);
    return resultList[k-1];
}

void dfs(int index, string result, vector<char> numList) {
    if(result.length() == numList.size()) {
        //cout << result << endl;
        resultList.push_back(result);
        return;
    }

    for(int i = 0; i < numList.size(); i++) {
        if(!visited[i]) {
            result += numList[i];
            visited[i] = true;
            dfs(i + 1, result, numList);
            visited[i] = false;
            result = result.substr(0, result.length()-1);
        }
    }
}