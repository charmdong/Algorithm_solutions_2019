#include <iostream>
#include <queue>
#define MAX 200
using namespace std;

struct water {
	int a, b, c;
};
int A, B, C;
bool visited[MAX + 1][MAX + 1]; // 부피가 A인 물통의 물의 양, 부피가 B인 물통의 물의 양 ★★★★
bool res[MAX + 1]; // 부피가 C인 물통의 물의 양

void bfs();
void print() {
	for (int i = 0; i <= C; i++)
		if (res[i])
			cout << i << " ";
	cout << endl;
}

int main()
{
	cin >> A >> B >> C;
	bfs();
	print();
	return 0;
}

void bfs() {
	queue<water> q;

	q.push({ 0,0,C });

	while (!q.empty()) {
		water now = q.front(); q.pop();

		if (visited[now.a][now.b])
			continue;

		visited[now.a][now.b] = true;

		if (now.a == 0)
			res[now.c] = true;

		// A -> B
		if (now.a + now.b > B)
			q.push({ now.a + now.b - B, B, now.c });
		else
			q.push({ 0, now.a + now.b, now.c });

		// A -> C
		if (now.a + now.c > C)
			q.push({ now.a + now.c - C, now.b, C });
		else
			q.push({ 0, now.b, now.a + now.c });

		// B -> A
		if (now.b + now.a > A)
			q.push({ A, now.b + now.a - A, now.c });
		else
			q.push({ now.b + now.a, 0, now.c });

		// B -> C
		if (now.b + now.c > C)
			q.push({ now.a, now.b + now.c - C, C });
		else
			q.push({ now.a, 0, now.b + now.c });

		// C -> A
		if (now.a + now.c > A)
			q.push({ A, now.b, now.a + now.c - A });
		else
			q.push({ now.a + now.c, now.b, 0 });

		// C -> B
		if (now.b + now.c > B)
			q.push({ now.a, B, now.b + now.c - B });
		else
			q.push({ now.a, now.b + now.c, 0 });
	}
}