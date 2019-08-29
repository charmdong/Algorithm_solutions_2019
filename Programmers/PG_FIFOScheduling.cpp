/// ���� ���� �����층

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> cores);

int main()
{
		cout << solution(50000, { 1,4,2,1,2,3,4,1,2,3,1,1,1,2,2,3,3,5,1,999,10,20,30,40,50,60 }) << endl;
		return 0;
}

// �� �ھ �۾��� �����ϰ� �ִ��� Ȯ���ϱ� ���� ���� �ʿ�.
int solution(int n, vector<int> cores) {
		vector<bool> isWork(cores.size(), false);
		vector<int> time(cores.size(), 0);

		while (n>0) {
				// �� �ھ �۾��� ���� ������ �˻�
				for (int i = 0; i < cores.size(); i++) {
						// �۾��� �����ְ�, ��� �ִ� �ھ �ִٸ� �� �ھ���� �۾� �Ҵ�
						if (n > 0 && !isWork[i]) {
								isWork[i] = true;
								n--; // �۾��� �ٿ��ֱ�
								if (n == 0) // ������ �۾��� �Ҵ��� ��� �ش� �ھ� ��ȣ ��ȯ
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