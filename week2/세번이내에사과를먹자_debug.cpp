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

	// 탐색하지 않을 조건
	if (x >= 5 || y >= 5) return;
	if (x < 0 || y < 0) return;
	if (map[x][y] == -1) return;

	// 사과찾기
	if (map[x][y] == 1) count++; // 사과가 있다면 카운트 더하기
	if (depth <= 3) { 		    // depth가 3보다 작거나 같은데 
		if (count >= 2) {       // 2개 이상의 사과 > 1을 반환, 리턴
			answer = 1;
			return;
		}
	}
	else { return; } // depth가 3을 넘어가면 더 계산한 필요가 없다

	map[x][y] = -1;  // 지나간 길은 장애물이 생긴다

	for (int i = 0; i < 4; i++) {
		if (answer == 1) return; // 정답이 나왔으면 더이상 반복하지 않는다
		int nx, ny;
		nx = x + dx[i];
		ny = y + dy[i];

		Dfs(make_pair(nx, ny), depth + 1, count);
	}
}
int main() {
	//map 데이터 업데이트
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
	//DFS 시작
	Dfs(make_pair(x, y), 0, 0);

	//정답출력
	cout << answer;
}
