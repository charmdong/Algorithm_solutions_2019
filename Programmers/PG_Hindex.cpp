#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int total = citations.size();

    sort(citations.begin(), citations.end());

    for(int num = 1; num <= total; num++) {
        int cnt = 0;

        for(int c : citations) {
            if(num <= c) {
                cnt++;
            }
        }

        if(cnt >= num) {
            answer = num;
        }
    }

    return answer;
}