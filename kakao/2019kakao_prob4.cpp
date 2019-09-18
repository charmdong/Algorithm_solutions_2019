#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    map<string, int> map;
    int querySize = queries.size();

    for(auto iter = queries.begin(); iter != queries.end(); iter++) {
        string query = *iter;
        string keyWord = "";
        int queryLen = query.length();
        bool isTail = (query[0] != '?');

        if(map.find(query) != map.end()) {
            answer.push_back(map[query]);
            continue;
        }

        for (int i = 0; i < queryLen; i++)
        {
            if (query[i] != '?')
            {
                keyWord += query[i];
            }
        }

        int count = 0;
        for(auto witer = words.begin(); witer != words.end(); witer++) {
            string str = *witer;
            if(str.length() == queryLen) {
                string subStr;

                if(isTail) {
                    subStr = str.substr(0, keyWord.length());
                } else {
                    subStr = str.substr(queryLen - keyWord.length());
                }
                
                if(subStr == keyWord) {
                    count++;
                }
            }
        }
        map.insert({query, count});
        answer.push_back(count);
    }

    return answer;
}

int main()
{
    vector<int> res = solution({"frodo", "front", "frost", "frozen", "frame", "kakao"}, {"fro??", "????o", "fr???", "fro???", "pro?", "???????", "fro??"});
    for(int t : res){
        cout << t << " ";
    }
    return 0;
}