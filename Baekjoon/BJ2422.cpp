#include <iostream>
#include <vector>

using namespace std;

int answer;
int n, m;
vector<vector<bool>> banList;

vector<vector<int>> bans;
vector<bool> isUsed;
vector<int> test;

void iteration();
void recursive(int cnt = 0, int cur = 1);

int main()
{
    int first, second;
    cin >> n >> m;

    banList.assign(n + 1, vector<bool>(n + 1, false));
    isUsed.assign(n + 1, false);

    bans.assign(n + 1, vector<int>());

    for(int iter = 0; iter < m; iter++) {
        cin >> first >> second;
        //banList[first][second] = banList[second][first] = true;
        
        bans[first].push_back(second);
        bans[second].push_back(first);
    }


    //iteration();
    recursive();
    cout << answer << endl;

    return 0;
}

void iteration() {
    for(int first = 1; first <= n; first++) {
        for(int second = first + 1; second <= n; second++) {
            if(banList[first][second]) {
                continue;
            }

            for(int third = second + 1; third <= n; third++) {
                if(banList[first][third] || banList[second][third]) {
                    continue;
                }
                answer++;
            }
        }
    }
}

void recursive(int cnt, int cur) {
    if(cnt == m) {
        answer++;
        return;
    }

    for(int index = cur; index <= n; index++) {
        if(isUsed[index]) {
            continue;
        }

        //test.push_back(index);
        isUsed[index] = true;
        for(int next = 0; next < bans[index].size(); next++) {
            int banIndex = bans[index][next];
            isUsed[banIndex] = true;
        }

        recursive(cnt + 1, index + 1);
        
        for (int next = 0; next < bans[index].size(); next++) {
            int banIndex = bans[index][next];
            isUsed[banIndex] = false;
        }
        isUsed[index] = false;
        //test.pop_back();
    }
}