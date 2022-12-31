#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;// 행열
bool check[101][101] = { 0 };//방문기록
int bfsMap[101][101] = { 0 };//bfs진행거리체크

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };// 오른, 아래, 왼, 위

queue<pair<int, int>> q;
int solution(vector<vector<int>>maps) {
	int answer = 0;
	n = maps[0].size();//가로
	m = maps.size();//세로

	// 시작점
	q.push(make_pair(0, 0));
	check[0][0] = true;
	bfsMap[0][0] = 1;

	//bfs 시작
	//q를 모두 소진하거나 목적지에 도달했을 때 멈춤
	while (!q.empty()) //|| bfsMap[m - 1][n - 1] != 0 <- 이건 왜 에러가 나는 걸까?
	{
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // 지정된 영역을 벗어난 경우
			if (check[nx][ny])continue;                           // 갔다 온 곳일 경우
			if (maps[nx][ny] == 0)continue;						  // 갈 수 있는 곳이 아닌 경우

			check[nx][ny] = true;								  // 방문표시
			q.push(make_pair(nx, ny));							  // 현재위치 queue에 넣기
			bfsMap[nx][ny] = bfsMap[curX][curY] + 1;			  // 이전 bfs진행거리에 1 더하기
		}
	}

	if (!bfsMap[m - 1][n - 1]) answer = -1;
	else answer = bfsMap[m - 1][n - 1];

	return answer;
}