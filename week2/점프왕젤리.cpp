#include <iostream>
#include <vector>
#include <queue>
# define pii pair<int,int>
using namespace std;


vector<vector<bool>> visited;
string answer = "Hing";

void solution(int mapSize, vector<vector<int>> map)
{
	queue<pii> q;
	q.push(make_pair(0, 0));     // queue에 시작점을 넣고 출발

	while (!q.empty()) 
	{
		auto now = q.front(); q.pop();
		int x = now.first, y = now.second;
		int step = map[x][y];                 // step에서 갈 수 있는 거리를 뽑는다

		if (visited[x][y] == true) continue;  // 방문했다면 지나간다
		visited[x][y] = true;                 // 지나치치 않았다면 방문기록

		if (step == -1) { answer = "HaruHaru"; break; }  // 끝점을 만나면 정답반환 후 반복문 파괴!
		if (step == 0) continue;

		if(x+step < mapSize) q.push(make_pair(x + step, y));  // 가로 세로의 경우 모두 큐에 넣어준다
		if(y+step < mapSize) q.push(make_pair(x, y + step));  // 큐에 들어간 것에서 다음 스탭으로 진행하기 때문에 정답 찾을 수 잇다
	}
}

int main()
{
	int mapSize;
	cin >> mapSize;
	vector<vector<int>> map(mapSize);
	visited.resize(mapSize);

	for (int i = 0; i < mapSize; i++)
	{
		for (size_t j = 0; j < mapSize; j++)
		{
			int input;
			cin >> input;
			map[i].push_back(input);
			visited[i].push_back(false);
		}
	}
	solution(mapSize, map);

	cout << answer;
}

// ref      : https://star-crab.tistory.com/41
// problem  : https://www.acmicpc.net/problem/16173
// keyPoint : cin >> int & push_back, resize, define, auto, make_pair