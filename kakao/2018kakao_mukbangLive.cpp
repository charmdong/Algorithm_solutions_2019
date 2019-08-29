#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>, long long);
bool cmp(pair<int, int> p1, pair<int,int> p2) {
    return p1.second < p2.second;
}

int solution(vector<int> foodTimes, long long k) {
    vector<pair<int, int>> tmp;
    int size = foodTimes.size();

    for(int i = 0; i < size; i++) {
        tmp.push_back({foodTimes[i], i + 1});
    }

    sort(tmp.begin(), tmp.end());

    
}