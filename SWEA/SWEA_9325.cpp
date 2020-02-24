#include <iostream>
#include <vector>

using namespace std;

int TC;
int N, P, D;
int solution(vector<int> productList);

int main()
{
    vector<int> productList;

    cin >> TC;

    for(int test = 1; test <= TC; test++) {
        cin >> N >> P >> D;

        productList.assign(N, 0);
        for(int index = 0; index < N; index++) {
            cin >> productList[index];
        }

        cout << "#" << test << " " << solution(productList) << endl;
    }

    return 0;
}

int solution(vector<int> productList) {
    // TODO:
}