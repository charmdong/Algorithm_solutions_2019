#include <iostream>
#include <string>
using namespace std;

int solution(string str);

int main()
{
    string str;
    cin >> str;
    cout << solution(str);
    return 0;
}

int solution(string str) {
    int strLen = str.length();
    int total = 0;

    for(int i=0; i<strLen; i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            total++;
        }
    }

    return total;
}