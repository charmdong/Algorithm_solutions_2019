#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solution(vector<string> cardList);

int main()
{
    int n;
    vector<string> cardList;

    cin >> n;
    cardList.assign(n, "");

    for(int index = 0; index < n; index++) {
        cin >> cardList[index];
    }    

    solution(cardList);

    return 0;
}

void solution(vector<string> cardList) {
    string answer = "Y";
    vector<int> countList;

    sort(cardList.begin(), cardList.end());

    string name = cardList[0];
    int cnt = 1;

    for(int index = 1 ; index < cardList.size(); index++) {
        if(name == cardList[index]) {
            cnt++;
        } else {
            countList.push_back(cnt);
            cnt = 1;
            name = cardList[index];
        }
    }

    countList.push_back(cnt);

    bool check = false;
    int maxVal = *max_element(countList.begin(), countList.end());

    for(int t : countList) {
        if(maxVal == t){
            continue;
        }

        if(maxVal - t > 1) {
            answer = "N";
            break;
        } else {
            if(!check) {
                check = true;
            } else {
                answer = "N";
                break;
            }
        }
    }    

    int total = 0;
    for(int t : countList) {
        total += t;
    }

    if(answer == "Y") {
        if(total % countList.size() != 0) {
            total++;
        }
    }

    cout << answer << endl;
    cout << total << endl;
    cout << countList.size() << endl;
} 