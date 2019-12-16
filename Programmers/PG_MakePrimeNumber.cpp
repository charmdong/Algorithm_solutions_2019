#include <vector>

using namespace std;

bool isPrime(int n);
void dfs(int& answer, int index, vector<int> nums, int numCnt = 0, int total = 0);

int solution(vector<int> nums) {
    int answer = 0;

    dfs(answer, 0, nums);

    return answer;
}

bool isPrime(int n) {
    bool answer = true;

    for(int num = 2; num <= n / 2; num++) {
        if(n % num == 0) {
            answer = false;
            break;
        }
    }

    return answer;
}

void dfs(int& answer, int index, vector<int> nums, int numCnt, int total) {
    if(numCnt == 3) {
        if(isPrime(total)) {
            answer++;
        }

        return;
    }

    for(int cur = index; cur < nums.size(); cur++) {
        dfs(answer, cur + 1, nums, numCnt + 1, total + nums[cur]);
    }
}