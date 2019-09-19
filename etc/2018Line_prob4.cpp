/**
 *  시간복잡도 : O(n)
 *  공간복잡도 : O(1)
 */

#include <iostream>
#include <string>
using namespace std;

string solution(string str);

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        cout << solution(str) << endl;
    }

    return 0;
}

string solution(string str) {
    string answer = "";
    int dupCount = 1;
    char curCh = str[0];

    for(int i=1; i<str.length(); i++) {
        if(str[i] == curCh) {
            dupCount++;
        } else {
            answer += (to_string(dupCount) + curCh);
            curCh = str[i];
            dupCount = 1;
        }
    }
    answer += (to_string(dupCount) + curCh);

    return answer;
}