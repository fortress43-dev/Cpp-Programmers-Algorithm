#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;// �࿭
bool check[101][101] = { 0 };//�湮���
int bfsMap[101][101] = { 0 };//bfs����Ÿ�üũ

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };// ����, �Ʒ�, ��, ��

queue<pair<int, int>> q;
int solution(vector<vector<int>>maps) {
	int answer = 0;
	n = maps[0].size();//����
	m = maps.size();//����

	// ������
	q.push(make_pair(0, 0));
	check[0][0] = true;
	bfsMap[0][0] = 1;

	//bfs ����
	//q�� ��� �����ϰų� �������� �������� �� ����
	while (!q.empty()) //|| bfsMap[m - 1][n - 1] != 0 <- �̰� �� ������ ���� �ɱ�?
	{
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // ������ ������ ��� ���
			if (check[nx][ny])continue;                           // ���� �� ���� ���
			if (maps[nx][ny] == 0)continue;						  // �� �� �ִ� ���� �ƴ� ���

			check[nx][ny] = true;								  // �湮ǥ��
			q.push(make_pair(nx, ny));							  // ������ġ queue�� �ֱ�
			bfsMap[nx][ny] = bfsMap[curX][curY] + 1;			  // ���� bfs����Ÿ��� 1 ���ϱ�
		}
	}

	if (!bfsMap[m - 1][n - 1]) answer = -1;
	else answer = bfsMap[m - 1][n - 1];

	return answer;
}