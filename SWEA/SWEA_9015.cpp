#include <iostream>
#include <vector>
#define INC 1
#define NON 0
#define DEC -1

using namespace std;

int TC, n;
int solution(vector<int> v);

int main()
{
    vector<int> v;
    cin >> TC;

    for(int test = 1; test <= TC; test++) {
        cin >> n;
        
        v.assign(n, 0);
        
        for(int index = 0; index < n; index++) {
            cin >> v[index];
        }

        cout << "#" << test << " " << solution(v) << endl;
    }

    return 0;
}

int solution(vector<int> v) {
    int answer = 1;
    int status;

    if(v[0] < v[1]) {
        status = INC;
    } else if(v[0] > v[1]) {
        status = DEC;
    } else {
        status = NON;
    }

    for(int index = 1; index < n - 1; index++) {
        // CASE : Increasement
        if(status == INC) {
            if(v[index] > v[index + 1]) {
                answer++;
                status = NON;
            }
        } 
        // CASE : Decreasement
        else if(status == DEC) {
            if(v[index] < v[index + 1]) {
                answer++;
                status = NON;
            }
        }
        // CASE : None
        else {
            if(v[index] < v[index + 1]) {
                status = INC;
            } else if(v[index] > v[index + 1]) {
                status = DEC;
            } 
        }
    }

    return answer;
}