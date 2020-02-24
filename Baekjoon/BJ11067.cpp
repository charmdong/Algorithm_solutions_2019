/**
 * @author : donggun.chung
 * @date : 2020.02.06
 * @site : 
 * @prob_Info : 
 * @time : 
 * @memory : 
 */

#include <iostream>
#include <vector>
#define HEIGHT 100000
#define ROW 0
#define COL 1
#define POS 2

int t, n, m, x, y;
vector<vector<int>> cafeList;
vector<int> numList;

using namespace std;

void solution();

int main()
{
    cin >> t;

    for(int test = 0; test < t; test++) {
        cin >> n;
        cafeList.assign(n, vector<int>(3, 0));

        for(int index = 0; index < n; index++) {
            cin >> x >> y;
            cafeList[index][ROW] = y + HEIGHT;
            cafeList[index][COL] = x;
        }

        cin >> m;
        numList.assign(m, 0);

        for(int index = 0; index < m; index++) {
            cin >> numList[index];
        }

        solution();
    }

    return 0;
}

void solution() {
    for(int index = 0; index < m; index++) {
        
    }
}