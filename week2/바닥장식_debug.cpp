#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> visited;
vector<vector<int>>  room;
int sum = 0;
void CheckTile(int curTile, int x, int y, int d, int w) {

	if (x >= d || y >= w) { sum++; return; }
	if (curTile != room[x][y]) { sum++; return; }

	if (curTile == 0){ CheckTile(room[x][y], x+1, y, d, w); }
	if (curTile == 1){ CheckTile(room[x][y], x, y+1, d, w); }
	visited[x][y] = true;

}

void solution(int d, int w, vector<vector<int>> room) {
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visited[i][j] == true) continue;
			CheckTile(room[i][j], i, j, d, w);		
		}
	}
}

int main() {
	int d, w; cin >> d >> w;
	room.resize(d); visited.resize(w);

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			char temp; cin >> temp;
			if (temp == '-') room[i].push_back(0);
			else room[i].push_back(1);

			visited[i].push_back(false);
		}
	}
	solution(d, w, room);
	cout << sum;
	return 0;
}