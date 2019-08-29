#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool solution(string str);

int main()
{
    int n;
    int res = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (solution(str))
        {
            res++;
        }
    }
    cout << res << endl;

    return 0;
}

bool solution(string str)
{
    stack<char> s;
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (!s.empty())
        {
            (s.top() == str[i]) ? s.pop() : s.push(str[i]);
        }
        else
        {
            s.push(str[i]);
        }
    }

    if(!s.empty()){
        return false;
    }

    return true;
}