/**
 * @author : donggun.chung
 * @date : 2020.02.18
 * @site : BOJ
 * @prob_Info : 14620 꽃길
 * @time : 44ms
 * @memory : 1988KB
 */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N, answer = INT_MAX;
vector<vector<int>> price;
vector<pair<int, int>> flower;
vector<vector<bool>> visited;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void solution();
void selectPosition(int row = 0, int col = 0);
bool checkPosition();
int getTotalPrice();
bool isInBoard(int y, int x);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    price.assign(N, vector<int>(N, 0));

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            cin >> price[row][col];
        }
    }

    solution();

    return 0;
}

void solution() {
    selectPosition();
    cout << answer << endl;
}

void selectPosition(int row, int col) {
    if(flower.size() == 3) {
        if(!checkPosition()) return;

        int res = getTotalPrice();

        if(answer > res) {
            answer = res;
        }
        return;
    }

    for(int r = row; r < N; r++) {
        if(r > row) {
            col = 1;
        }
        for(int c = col; c < N; c++) {
            flower.push_back({r, c});
            
            if(c + 1 < N) {
                selectPosition(r, c + 1);
            } else {
                selectPosition(r + 1, 1);
            }
            
            flower.pop_back();
        }
    }
}

bool checkPosition() {
    visited.assign(N, vector<bool>(N, false));

    for(pair<int, int> f : flower) {
        visited[f.first][f.second] = true;

        for(int dir = 0; dir < 4; dir++) {
            int ny = f.first + dy[dir];
            int nx = f.second + dx[dir];

            if(isInBoard(ny ,nx) && !visited[ny][nx]) {
                visited[ny][nx] = true;
            }  else {
                return false;
            }
        }
    }

    return true;
} 

int getTotalPrice() {
    int total = 0;

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            if(visited[row][col]) {
                total += price[row][col];
            }
        }
    }

    return total;
}

bool isInBoard(int y, int x) {
    return (y > -1 && y < N && x > -1 && x < N);
}