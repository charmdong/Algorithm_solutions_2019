/**
 * BJ : printer Queue
 */ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& q, vector<int>& index, int m);

int main()
{
    int testCase, n, m;
    cin >> testCase;

    while(testCase--) {
        vector<int> q, index;

        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            int important;

            index.push_back(i);
            cin >> important;
            q.push_back(important);
        }

        cout << solution(q, index, m) << endl;
    }

    return 0;
}

int solution(vector<int>& q, vector<int>& index, int m) {
    int answer = 0;

    while(!q.empty()) {
        if(q.front() == *max_element(q.begin(), q.end())) {
            answer++;

            if(index.front() == m) {
                return answer;
            }

            q.erase(q.begin());
            index.erase(index.begin());
        } else {
            q.push_back(q.front());
            q.erase(q.begin());

            index.push_back(index.front());
            index.erase(index.begin());
        }
    }
}