#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> dataList);
bool cmp(vector<int>, vector<int>);

int main()
{
    //vector<int> ans = solution({{1,0,5},{2,2,2},{3,3,1},{4,4,1},{5,10,2}});
    vector<int> ans = solution({{1,0,3},{2,1,3},{3,3,2},{4,9,1},{5,10,2}});
    //vector<int> ans = solution({{1, 2, 10}, {2, 5, 8}, {3, 6, 9}, {4, 20, 6}, {5, 25, 5}});
    for (int t : ans)
    {
        cout << t << " ";
    }
    return 0;
}

bool cmp(vector<int> v1, vector<int> v2)
{
    if (v1[2] == v2[2])
    {
        return (v1[1] < v2[2]);
    }
    return v1[2] < v2[2];
}

vector<int> solution(vector<vector<int>> dataList)
{
    vector<int> answer;
    deque<vector<int>> wait;
    int requestCount = dataList.size();
    int checkIndex = 0;
    int curIndex = 0, nextIndex = 0;
    int endTime = dataList[curIndex][1];
    int count = 0;

    while (count < requestCount)
    {
        curIndex = nextIndex;

        vector<int> curData = dataList[curIndex];
        int curDocNum = curData[0];
        int curPage = curData[2];

        answer.push_back(curDocNum); // 인쇄 시작하는 문서
        endTime += curPage;

        // 대기열 검사
        for (int search = checkIndex + 1; search < requestCount; search++)
        {
            vector<int> data = dataList[search];
            int docNum = data[0];
            int requestTime = data[1];
            
            if (search == curIndex) {
                checkIndex++;
                continue;
            }

            if (endTime > requestTime)
            {
                wait.push_back(data);
            }
            else if (endTime == requestTime)
            {
                wait.push_front(data);
            }
            else
            { // 끝나는 시간보다 요청이 늦는 경우
                break;
            }

            checkIndex = search;
        }

        // 대기열 없는 경우
        if (wait.empty())
        {
            nextIndex = checkIndex + 1;
        }
        else
        { // 대기열 있는 경우
            sort(wait.begin(), wait.end(), cmp);
            nextIndex = wait.front()[0] - 1; // nextDocNum - 1
            wait.pop_front();
        }
        count++;
    }

    return answer;
}