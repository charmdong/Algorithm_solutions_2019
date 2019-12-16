#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;

    st.push(s[0]);

    for(int index = 1; index < s.length(); index++) {
        if(st.empty()) {
            st.push(s[index]);
        } else {
            if(st.top() == s[index]) {
                st.pop();
            } else {
                st.push(s[index]);
            }
        }
    }
    
    answer = st.empty() ? 1 : 0;

    return answer;
}