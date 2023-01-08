#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int map[5][5] = {0};
bool visited[5][5] = { false };
int dx[2] = {-1, 1};
int dy[2] = {-1, 1};

void Dfs(pair<int,int> pos, int depth, int count) {
	int x = pos.first;
	int y = pos.second;
	
	// Ž������ ���� ����
	if (x >= 5 || y >= 5) return;
	if (x < 0 || y < 0) return;

	if (visited[x][y] == true) return;
	if (map[x][y] == -1) return;

	
	if (map[x][y] = 1) count++; // ����� �ִٸ� ī��Ʈ ���ϱ�
	if (depth <= 3) { 		    // depth�� 3���� �۰ų� ������ 
		if (count >= 2) {       // 2�� �̻��� ��� > 1�� ��ȯ, ����
			answer = 1;
			return;
		}
	}
	else { return; } // depth�� 3�� �Ѿ�� �� ����� �ʿ䰡 ����

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			if (answer == 1) return; // ������ �������� ���̻� �ݺ����� �ʴ´�
			int nx, ny;
			nx = x+dx[i];
			ny = y+dy[j];

			Dfs(make_pair(x, y), depth + 1, count);
		}
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
	visited[x][y] = true;
	Dfs(make_pair(x, y), 0, 0);

	//�������
	cout << answer;
}
