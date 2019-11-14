/**
 * PG : Tower
 */ 
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> h) {
    vector<int> answer;

    for(int now = 0; now < h.size(); now++) {
        bool find = false;

        for(int index = now - 1; index >= 0; index--) {
            if(h[index] > h[now]) {
                answer.push_back(index + 1);
                find = true;
                break;
            }
        }

        if(!find) {
            answer.push_back(0);
        }
    }

    return answer;
}

int main()
{
    vector<int> res = solution({6,9,5,7,4});

    for(int t : res) {
        cout << t << " ";
    }

    return 0;
}