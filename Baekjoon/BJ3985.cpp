/**
 * @author : donggun.chung
 * @date : 2020.02.09
 * @site : BOJ
 * @prob_Info : 3985 롤 케이크
 * @time : 0ms
 * @memory : 1984KB
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<int> cake, cnt;

int main()
{
    int p, k, max = 0, maxIndex = 0;

    cin >> L >> N;
    cake.assign(L + 1, 0);
    cnt.assign(N + 1, 0);

    for(int index = 1; index <= N; index++) {
        cin >> p >> k;
        int diff = k - p;

        if(diff > max) {
            max = diff;
            maxIndex = index;
        }
        
        for(int aud = p; aud <= k; aud++) {
            if(cake[aud] == 0) {
                cake[aud] = index;
            }
        }
    }

    cout << maxIndex << endl;

    for(int index = 1; index <= L; index++) {
        cnt[cake[index]]++;
    }

    max = 0;
    maxIndex = 0;

    for(int index = 1; index <= N; index++) {
        if(max < cnt[index]) {
            max = cnt[index];
            maxIndex = index;
        }
    }

    cout << maxIndex << endl;

    return 0;
}