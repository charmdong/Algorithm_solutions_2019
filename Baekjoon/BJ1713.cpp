/**
 * @author : donggun.chung
 * @date : 2020.02.15
 * @site : BOJ
 * @prob_Info : 1713 후보 추천하기 
 * @time : 0ms
 * @memory : 1984KB
 */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N, M;
vector<pair<int, int>> candidate(101, {0, 0});

void removeCandidate();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, pic = 0;
    cin >> N >> M;

    for(int index = 0; index < M; index++) {
        cin >> num;

        // 사진 틀이 비어있지 않은 경우
        if(pic >= N) {
            // 새로운 추천자의 등장
            if(candidate[num].first == 0) {
                removeCandidate();
            } 
        } else {
            if(candidate[num].first == 0)
                pic++;
        }

        candidate[num].first++;
        
        // 사진이 게시된 얘들 등록 날짜 증가
        for(int iter = 1; iter <= 100; iter++) {
            if(candidate[iter].first == 0) continue;
            candidate[iter].second++;
        }
    }

    for(int index = 1; index <= 100; index++) {
        if(candidate[index].first != 0) {
            cout << index << " ";
        }
    }
    cout << endl;

    return 0;
}

void removeCandidate() {
    int minIndex = 0;
    pair<int, int> minInfo = {INT_MAX, INT_MAX};

    for(int index = 1; index <= 100; index++) {
        if(candidate[index].first == 0) continue;

        pair<int, int> now = candidate[index];

        if(now.first < minInfo.first) {
            minIndex = index;
            minInfo = now;
        } else if(now.first == minInfo.first) {
            if(now.second > minInfo.second) {
                minIndex = index;
                minInfo = now;
            }
        }
    }

    candidate[minIndex] = {0, 0};
}