#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int map[5][5] = { 0 };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void Dfs(pair<int, int> pos, int depth, int count) {
	int x = pos.first;
	int y = pos.second;

	// Ž������ ���� ����
	if (x >= 5 || y >= 5) return;
	if (x < 0 || y < 0) return;
	if (map[x][y] == -1) return;

	// ���ã��
	if (map[x][y] == 1) count++; // ����� �ִٸ� ī��Ʈ ���ϱ�
	if (depth <= 3) { 		    // depth�� 3���� �۰ų� ������ 
		if (count >= 2) {       // 2�� �̻��� ��� > 1�� ��ȯ, ����
			answer = 1;
			return;
		}
	}
	else { return; } // depth�� 3�� �Ѿ�� �� ����� �ʿ䰡 ����

	map[x][y] = -1;  // ������ ���� ��ֹ��� �����

	for (int i = 0; i < 4; i++) {
		if (answer == 1) return; // ������ �������� ���̻� �ݺ����� �ʴ´�
		int nx, ny;
		nx = x + dx[i];
		ny = y + dy[i];

		Dfs(make_pair(nx, ny), depth + 1, count);
	}
}
int main() {
	//map ������ ������Ʈ
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
		}
	}

	int x, y;
	cin >> x;
	cin >> y;
	//DFS ����
	Dfs(make_pair(x, y), 0, 0);

	//�������
	cout << answer;
}
