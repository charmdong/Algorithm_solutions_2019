/// 선입 선출 스케쥴링

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> cores);

int main()
{
		cout << solution(50000, { 1,4,2,1,2,3,4,1,2,3,1,1,1,2,2,3,3,5,1,999,10,20,30,40,50,60 }) << endl;
		return 0;
}

// 각 코어가 작업을 실행하고 있는지 확인하기 위한 변수 필요.
int solution(int n, vector<int> cores) {
		vector<bool> isWork(cores.size(), false);
		vector<int> time(cores.size(), 0);

		while (n>0) {
				// 각 코어가 작업을 수행 중인지 검사
				for (int i = 0; i < cores.size(); i++) {
						// 작업이 남아있고, 놀고 있는 코어가 있다면 앞 코어부터 작업 할당
						if (n > 0 && !isWork[i]) {
								isWork[i] = true;
								n--; // 작업량 줄여주기
								if (n == 0) // 마지막 작업을 할당한 경우 해당 코어 번호 반환
										return i + 1;
						}
						time[i]++;
						if (cores[i] == time[i]) {
								isWork[i] = false;
								time[i] = 0;
						}
				}

				/*for (int i = 0; i < cores.size(); i++) {
						time[i]++;
						if (cores[i] == time[i]) {
								isWork[i] = false;
								time[i] = 0;
						}
				}*/
		}
}