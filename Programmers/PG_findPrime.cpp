/**
 * PG : 소수 찾기 - 완전탐색(bruth-force)
 */ 
#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

bool isPrime(int num) {
    if(num < 2) {
        return false;
    }

    for(int i = 2; i < num/2; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(set<int>& numList, vector<bool> visited, string numbers, string num) {
    if(num.length() > 0) {
        numList.insert(stoi(num));
    }

    if(num.length() == numbers.length()) {
        return;
    }

    for(int index = 0; index < numbers.length(); index++) {
        if(!visited[index]) {
            visited[index] = true;
            dfs(numList, visited, numbers, num + numbers[index]);
            visited[index] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;

    vector<bool> visited(numbers.length(), false);
    set<int> numList;

    dfs(numList, visited, numbers, "");
    
    for(auto iter = numList.begin(); iter != numList.end(); iter++) {
        if(isPrime(*iter)) {
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout << "\n" << solution("132") << endl;

    return 0;
}