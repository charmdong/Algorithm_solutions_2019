#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int cur = 0; cur < prices.size(); cur++) {
        int time = 0;

        for(int next = cur + 1; next < prices.size(); next++) {
            if(prices[next] < prices[cur]) {
                time++;
                break;
            }

            time++;
        }

        answer.push_back(time);
    }

    return answer;
}