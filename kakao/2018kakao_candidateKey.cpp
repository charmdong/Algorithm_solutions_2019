#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool visited[8];
vector<int> keyList;

void dfs(vector<int> noneKeyList, vector<vector<string>> relation, int &answer, int startIndex = 0);
bool isCandidate(vector<vector<string>> relation);
int solution(vector<vector<string>> relation);

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int attrCount = relation[0].size();
    vector<int> noneKeyList;

    for(int index = 0; index < attrCount; index++) {
        keyList.push_back(index);
        if(!isCandidate(relation)) {
            noneKeyList.push_back(index);
        } else {
            answer++;
        }
        keyList.pop_back();
    }

    dfs(noneKeyList, relation, answer);

    return answer;
}

void dfs(vector<int> noneKeyList, vector<vector<string>> relation, int &answer, int startIndex)
{
    // 최소성 검사를 못하겠다 씨벌
    if(isCandidate(relation)) {
        answer++;
        return;
    }

    for(int i = startIndex; i < noneKeyList.size(); i++) {
        int index = noneKeyList[i];
        if(!visited[index]) {
            visited[index] = true;
            keyList.push_back(index);
            dfs(noneKeyList, relation, answer, i + 1);
            keyList.pop_back();
            visited[index] = false;
        }
    }
}

bool isCandidate(vector<vector<string>> relation)
{
    if(keyList.empty()) {
        return false;
    }

    set<string> tupleList;
    int tupleCount = relation.size();

    for(int row = 0; row < tupleCount; row++) {
        string tupleStr = "";
        for(int col : keyList) {
            tupleStr += relation[row][col];
        }
        tupleList.insert(tupleStr);
    }

    return tupleList.size() == tupleCount;
}

int main()
{
    vector<vector<string>> r1 = {{"100","ryan","music","2"},
    {"200","apeach","math","2"},
    {"300","tube","computer","3"},
    {"400","con","computer","4"},
    {"500","muzi","music","3"},
    {"600","apeach","music","2"}};

    vector<vector<string>> r2 = {{"100","ryan","music","2","1"},
    {"200","apeach","math","2", "2"},
    {"300","tube","computer","3", "3"},
    {"400","con","computer","4", "4"},
    {"500","muzi","music","3", "5"},
    {"600","apeach","music","2", "6"}};


    cout << solution(r1) << endl;

    return 0;
}