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
	q.push(make_pair(0, 0));

	while (!q.empty()) 
	{
		auto now = q.front(); q.pop();
		int x = now.first, y = now.second;
		int step = map[x][y];

		if (visited[x][y] == true) continue;
		visited[x][y] = true;

		if (step == -1) { answer = "HaruHaru"; break; }
		if (step == 0) continue;

		if(x+step < mapSize) q.push(make_pair(x + step, y));
		if(y+step < mapSize) q.push(make_pair(x, y + step));
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