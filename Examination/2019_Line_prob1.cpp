#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int consumerCount, vector<int> messageList);

int main(void) {
    int conCount;
    int messageCount;
    vector<int> messageList;

    cin >> messageCount >> conCount;
    messageList.assign(messageCount, 0);

    for(int index = 0; index < messageCount; index++) {
        cin >> messageList[index];
    }

    cout << solution(conCount, messageList);

    return 0;
}

int solution(int n, vector<int> messageList) {
    vector<int> consumer(n, 0);
    int len = messageList.size();

    for(int i = 0; i < n; i++) {
        consumer[i] = messageList[i];
    }

    for(int i = n; i < len; i++) {
        auto minIndex = min_element(consumer.begin(), consumer.end());
        *minIndex += messageList[i];
    }

    return *max_element(consumer.begin(), consumer.end());
}