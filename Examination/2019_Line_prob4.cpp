#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> seatList);

int main()
{
    int n;
    vector<int> seatList;

    cin >> n;
    seatList.assign(n, 0);

    for(int i=0; i<n; i++) {
        cin >> seatList[i];
    }

    cout << solution(seatList) << endl;

    return 0;
}

int solution(vector<int> seatList) {
    int seatLen = seatList.size();
    int answer = 0;

    for(int index = 0; index < seatLen; index++) {
        if(seatList[index] == 1) {
            continue;
        }

        int leftDist = 1;
        for(int left = index-1; left >= 0; left--) {
            if(seatList[left] == 1) {
                break;
            }
            leftDist++;
        }

        int rightDist = 1;
        for(int right = index + 1; right < seatLen; right++) {
            if(seatList[right] == 1) {
                break;
            }
            rightDist++;
        }
        
        if(index == 0) {
            answer = max(answer, rightDist);
        } else if (index == seatLen - 1) {
            answer = max(answer, leftDist);
        } else {
            answer = max(answer, min(leftDist, rightDist));
        }
    }

    return answer;
}