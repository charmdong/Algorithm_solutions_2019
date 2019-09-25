#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n) {
    vector<long long> answer;
    int startNum = 2;
    int count = 0;
    int midCount = 0;
    answer.push_back(2);

    for(int index = 1; index < n; index++) {
        count++;
        if(count % 4 == 0) {
            midCount++;

            int val = (midCount + 1) * (midCount + 2) * (midCount + 3);
            if(val == (startNum) * (startNum + 1)) {
                startNum++;
            }
            answer.push_back(val);
            count = 0;
            continue;
        }

        int res = startNum * (startNum + 1);
        answer.push_back(res);
        startNum++;
    }


    return answer.back();
}

int main(){
    int n;
    cin >> n;
    cout << solution(n) << endl;
    return 0;
}