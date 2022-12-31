#include <vector>
#include <iostream>
using namespace std;

int maxAlp, maxCop;
int cache[151][151];

int solve(int alp, int cop, vector<vector<int>>& problems) 
{
    for (vector<int> v : problems) 
    {
        maxAlp = max(maxAlp, v[0]);
        maxCop = max(maxCop, v[1]);
    }
	if (alp >= maxAlp && cop >= maxCop) return 0;

    // �ִ��� �Ѿ �� ���� ũ�� ����
    if (alp > maxAlp) alp = maxAlp;
    if (cop > maxCop) cop = maxCop;

    int& ret = cache[alp][cop];
    if (ret != 0) return ret;
    ret = 1e9;

    // ���� Ǯ��
    for (vector<int> v : problems) {
        int number = v[0];
        if (alp < v[0] || cop < v[1]) continue;
        ret = min(ret, solve(alp + v[2], cop + v[3], problems) + v[4]);
    }

    // ����
    ret = min(ret, solve(alp + 1, cop, problems) + 1);
    ret = min(ret, solve(alp, cop + 1, problems) + 1);

    return ret;

}

int solution(int alp, int cop, vector<vector<int>> problems) {


    return solve(alp, cop, problems);
}

int main() {
    cout << solution(10, 10, {{10, 15, 2, 1, 2}, { 20, 20, 3, 3, 4 }});
}


