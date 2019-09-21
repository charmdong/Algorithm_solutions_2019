/**
 * PG : 입국심사
 * type : bianry search
 */ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long maxVal = times.back() * n;
    long long answer = maxVal;
    long long left = 1;
    long long right = maxVal;

    while(left <= right) {
        long long mid = (left + right) / 2;
        long long number = 0;
        
        for(int t: times) {
            number += (mid / t);
        }

        if(number < n) {
            left = mid + 1;
        } else {
            if(answer > mid) {
                answer = mid;
            }
            right = mid - 1;
        }
    }

    return answer;
}

int main()
{
    cout << solution(6, {7, 10}) << endl;
    return 0;
}