#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string FBI = "FBI";
    string answer = "";

    for(int i=0; i<5; i++) {
        string str;
        cin >> str;

        if(str.find(FBI, 0) != -1) { 
            answer += to_string(i + 1) + " ";
        }
    }

    if(answer != "") {
        cout << answer;
    } else {
        cout << "HE GOT AWAY!";
    }

    return 0;
}