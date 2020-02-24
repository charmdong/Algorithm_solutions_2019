/**
 * @author : donggun.chung
 * @date : 2020.02.11
 * @site : SWEA
 * @prob_Info : 1966 숫자를 정렬하자 
 * @time : 6ms
 * @memory : 12MB
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
vector<int> ary;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    for(int test = 1; test <= T; test++) {
        cin >> N;
        ary.assign(N, 0);

        for(int index = 0; index < N; index++) {
            cin >> ary[index];
        }

        sort(ary.begin(), ary.end());

        cout << "#" << test << " ";
        for(int num : ary) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}