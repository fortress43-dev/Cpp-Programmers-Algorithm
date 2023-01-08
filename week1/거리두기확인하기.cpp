#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, 2, -1,-2,  0, 0,  0,  0, 1, -1,  1, -1 };
int dy[] = { 0, 0,  0, 0,  1, 2, -1, -2, 1,  1, -1, -1 };

struct Pos { int x, y; };

int CheckRule(vector<vector<string>> places, Pos pPos)
{
	vector<Pos> peoples;
	Pos checkPos;

	int dst;

	for (int i = 0; i < 12; i++)
	{
		checkPos.x = pPos.x + dx[i];
		checkPos.y = pPos.y + dy[i];
		dst++;

		if (checkPos.x < 0 || checkPos.x > 5)continue;
		if (checkPos.y < 0 || checkPos.y > 5)continue;

		string object = places[checkPos.x][checkPos.y];
		
		if (dst >= 2)dst = 0;
		if (object == "X") continue;
		if (object == "P") return 1;
	}
}

vector<int> solution(vector<vector<string>> places)
{
	vector<int> answer;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (places[i][j] == "P");
			Pos pPos;

			pPos.x = i;
			pPos.y = j;

			answer.push_back(CheckRule(places, pPos));
		}
	}
	return answer;
}
