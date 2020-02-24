/**
 * @author : donggun.chung
 * @date : 2020.02.14
 * @site : BOJ
 * @prob_Info : 18429 근손실
 * @time : 0ms
 * @memory : 1984KB
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define LIMIT 500
using namespace std;

int N, K;
vector<int> kit, kIndex;

int solution();
bool checkWeight();

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    kit.assign(N, 0);

    for(int index = 0; index < N; index++) {
        cin >> kit[index];
    }

    kIndex.assign(kit.size(), 0);

    for(int index = 0; index < kit.size(); index++) {
        kIndex[index] = index;
    }

    cout << solution() << endl;

    return 0;
}

int solution() {
    int answer = 0;

    while(true) {
        if(checkWeight()) {
            answer++;
        }

        if(!next_permutation(kIndex.begin(), kIndex.end())) {
            break;
        }
    }

    return answer;
}

bool checkWeight() {
    int weight = 500;
    int len = kit.size();

    for(int index = 0; index < len; index++) {
        int cur = kIndex[index];

        weight = weight + kit[cur] - K;
        if(weight < LIMIT) {
            return false;
        }
    }
    
    return true;
}