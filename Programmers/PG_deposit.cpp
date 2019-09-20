/**
 * PG : 예산 - 이분법
 */ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgetList, int total) {
    int answer = 0;
    int num = budgetList.size();

    sort(budgetList.begin(), budgetList.end());

    for(int budget : budgetList) {
        if(budget < (total / num)) {
            total -= budget;
            num--;
        } else {
            return total / num;
        }
    }

    return budgetList.back();
}

int main()
{
    cout << solution({120, 110, 140, 150}, 485) << endl;
    return 0;
}