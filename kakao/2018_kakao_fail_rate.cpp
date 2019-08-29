#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages);
bool cmp(pair<double, int> p1, pair<double, int> p2) {
    if(p1.first == p2.first) {
        return p1.second < p2.second;
    }

    return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> failure;
    int userCount = stages.size();
    int reached[501] = {0};

    for(int i = 0; i < userCount; i++) { // 각 스테이지에 도달한 유저수
        reached[stages[i]]++;
    }

    // 스테이지별 실패율 구하기
    for(int i = 1; i <= N; i++) {
        if(reached[i] == 0) {
            failure.push_back({0, i});
        } else {
            failure.push_back({((double)reached[i]/ userCount), i});
            userCount -= reached[i];
        }
    }

    sort(failure.begin(), failure.end(), cmp);

    for(auto p : failure) {
        // cout << p.first << ", " << p.second << endl;
        answer.push_back(p.second);
    }

    return answer;
}

int main()
{
    //vector<int> res = solution(4, {4,4,4,4,4});
    vector<int> res2 = solution(5, {2,1,2,6,2,4,3,3});
    return 0;
}