#include <iostream>
#include <string>
#include <vector>

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
    int len = str.length();
    bool isPanlin = true;
    
    for(int i=0; i<len/2; i++) {
        if(str[i] != str[len-1-i]){
            isPanlin = false;
            break;
        }
    }

    return isPanlin ? 1 : 0;
}