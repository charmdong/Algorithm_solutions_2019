// �̻��� �ݸ�
#include <iostream>
#include <vector>
using namespace std;

struct micro {
	int y, x;
	int amount;
	int direct;
	micro(int y = 0, int x =0, int a = 0, int d = 0) :y(y),x(x), amount(a), direct(d) {}
};

int n,m,k;
int dy[5] = {0,-1,1,0,0};
int dx[5] = {0,0,0,-1,1};
vector<micro> mc;
//vector<int> map[100][100]; // �� ��ǥ�� ��ġ�� ������ ��ȣ�� ������ ����

bool isInDeath(int y, int x);
void solution();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		int ans = 0;
		cin >> n >> m >> k;
		mc.assign(k, micro());
		
		for (int j = 0; j < k; j++)
			cin >> mc[j].y >> mc[j].x >> mc[j].amount >> mc[j].direct;

		while (m--) {
			solution();
		}
		for (auto t : mc)
			ans += t.amount;

		cout << "#" << i << " " << ans << endl;
	}

	return 0;
}

void solution() { // 1�ð� �����ӿ� ���� �������� ��ġ ��ȭ
	for (auto &t : mc) { // �ش� �������� �����̱�
		if (t.amount == 0) continue; // ������ ���� ���
		t.y += dy[t.direct];
		t.x += dx[t.direct];
	}

	for (int i = 0; i < mc.size(); i++) {
		if (mc[i].amount != 0) { // ������ ��� �ִ� ���
			if (isInDeath(mc[i].y, mc[i].x)) {  // �๰ ģ ���� ��ġ�ߴٸ�
				if ((mc[i].amount /= 2) == 0) continue; // �̻����� �� �����ٸ� �н�
				mc[i].direct = (mc[i].direct % 2 == 0) ? mc[i].direct - 1 : mc[i].direct + 1; // ���� ����
				continue; // �๰ ģ �������� ������ ���� ���� ����
			}

			// ���� ��ĥ �� �ִ� ���
			int maxIndex = i;
			int na = mc[i].amount; // �̻��� ��

			for (int j = 0; j < mc.size(); j++) { // ������ ��ġ�� ��� Ž��
				if (mc[j].amount == 0 || i==j) continue; // ������ ���� ���
				if (mc[i].y == mc[j].y && mc[i].x == mc[j].x) { // ���� ��ǥ�� ��ġ�Ѵٸ�
					na += mc[j].amount;
					if (mc[maxIndex].amount < mc[j].amount) {
						mc[maxIndex].amount = 0;
						maxIndex = j;
					}
					else
						mc[j].amount = 0;
				}
			}
			mc[maxIndex].amount = na; // ��ġ�� ��� �� ���� ū ������ �̻��� �� ����
		}
	}
}

bool isInDeath(int y, int x) {
	return (y == 0 || y == n - 1 || x == 0 || x == n - 1);
}