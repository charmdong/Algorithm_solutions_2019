#include <iostream>
#include <vector>

using namespace std;

int N, M;
int answer;
vector<int> cardList;
void solution(vector<int> v, int cur = 0, int total = 0);

int main()
{
    vector<int> result;
    cin >> N >> M;

    cardList.assign(N, 0);

    for(int index = 0; index < N; index++) {
        cin >> cardList[index];
    }

    solution(result);

    cout << answer << endl;

    return 0;
}

void solution(vector<int> result, int cur, int total) {
    if(result.size() == 3) {
        if(total <= M) {
            if(answer < total) {
                answer = total;
            }
        }
        return;
    }

    for(int index = cur; index < N; index++) {
        result.push_back(cardList[index]);
        solution(result, index + 1, total + cardList[index]);
        result.pop_back();
    }
}