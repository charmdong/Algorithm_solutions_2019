#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string str1, string str2);

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        vector<int> res;
        string str1, str2;
        
        cin >> str1 >> str2;
        res = solution(str1, str2);

        cout << "Distances: ";
        for(int v : res) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<int> solution(string str1, string str2) {
    vector<int> answer;
    int len = str1.length();

    for (int i = 0; i < len; i++)
    {
        int diff = (str1[i] <= str2[i]) ? (str2[i] - str1[i]) : (str2[i] + 26) - str1[i];
        answer.push_back(diff);
    }

    return answer;
}