#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> visited;
vector<vector<int>> follow;
vector<int> candyList;

void solution(int index);

int main()
{
    int n;
    char card;
    int num;
    int index = 0;

    cin >> n;
    getchar();
    follow.assign(n, vector<int>());
    candyList.assign(n, 0);

    while (true)
    {
        scanf(" %c", &card);
        switch (card)
        {
        case 'K':
            cin >> num;
            follow[index].push_back(num);
            break;

        case 'A':
            candyList[index]++;
            visited.assign(n, false);

            for(int i : follow[index]) {
                solution(i);
            }

            break;

        case 'J':
            if (index > 0 && index < 4)
            {
                candyList[index - 1]++;
                candyList[index + 1]++;
            }
            else if (index == 0)
            {
                candyList[index + 1]++;
                candyList[n - 1]++;
            }
            else
            {
                candyList[index - 1]++;
                candyList[0]++;
            }

            visited.assign(n, false);

            for(int i : follow[index]) {
                solution(i);
            }

            break;

        case 'Q':
            for (int &t : candyList)
            {
                t++;
            }
            break;
        }

        index = (index + 1) % n;

        if (getchar() == '\n')
        {
            break;
        }
    }

    for (int c : candyList)
    {
        cout << c << " ";
    }

    return 0;
}

void solution(int index)
{
    visited[index] = true;
    candyList[index]++;

    for (int i = 0; i < follow[index].size(); i++)
    {
        int next = follow[index][i];

        if(!visited[next]) {
            solution(next);
        }
    }
}