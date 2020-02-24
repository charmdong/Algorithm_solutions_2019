#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
string pw;

void solution(int cur = 0, string candidate = "");
bool isGood(string candidate);

int main()
{   
    cin >> L >> C;

    pw.assign(C, 0);

    for(int index = 0; index < C; index++) {
        cin >> pw[index];
    }
    
    sort(pw.begin(), pw.end());
    solution();

    return 0;
}

void solution(int cur, string candidate) {
    if(candidate.size() == L) {
        if(isGood(candidate)) {
            cout << candidate << endl;
        }

        return;
    }

    for(int index = cur; index < C; index++) {
        solution(index + 1, candidate + pw[index]);
    }
}

bool isGood(string candidate) {
    bool answer = false;
    int vowel = 0;
    int cons = 0;
    
    for(int index = 0; index < L; index++) {
        if(vowel >= 1 && cons >= 2) {
            answer = true;
            break;
        }

        if (candidate[index] == 'a' ||
                candidate[index] == 'e' ||
                candidate[index] == 'i' ||
                candidate[index] == 'o' ||
                candidate[index] == 'u')
        {
            vowel++;
        } else {
            cons++;
        }
    }

    if(vowel >= 1 && cons >= 2) {
        answer = true;
    }

    return answer;
}