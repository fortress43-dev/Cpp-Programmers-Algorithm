#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int time_diff(string in, string out) {        // ������ ���� �ð��� ���̸� ���ϴ� �Լ�
    int h1 = stoi(in.substr(0, 2));           // stoi -> string to int
    int m1 = stoi(in.substr(3, 2));           // h : hour // m : minute
    int h2 = stoi(out.substr(0, 2));          // substr(0,2) -> index 0���� 2�� ����
    int m2 = stoi(out.substr(3, 2));

    int diff = (h2 - h1) * 60 + (m2 - m1);    // �ð��� ������ �ٲ��� -> hour * 60 + minute 

    return diff;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> m;                                      // map�� key�� ������������ �ڵ��������ش� // �������� ����Ʈ�� ����
                                                                        
    stringstream ss;                                                    // stringstream�� �������� ������ str�� �̾ƾ��� ����
    for (auto record : records) {                                       
        ss.str(record);                                                 // �۾��� ���� stringstream�� string�� �־��ش�
        string time, number, status; ss >> time >> number >> status;    // ���� string�� �̷� ������ ���� �� �ִ�

        m[number].push_back(time);                                      // map�� �����͸� �־��ش� -> key << carNumber , value << time 
        ss.clear();                                                     
    }

    for (auto it : m) {
        if (it.second.size() & 1) // ���� ���� Ȧ���� "23:59" �߰�
            it.second.push_back("23:59");

        vector<string> info = it.second;
        int total = 0;
        for (int i = 0; i < info.size() - 1; i += 2) {                  // �ݺ��� �� ¦�������� �����ؾ� �ؼ� ������ idx���� �ϸ� �ȵ�
            total += time_diff(info[i], info[i + 1]);                   // info�� �������� �������� �־ for������ ó��
        }

        int price = fees[1];                                              // �⺻����� ������ �ΰ�
        if (total > fees[0]) {                                            // �������ð��� �⺻�ð����� ũ�ٸ�
            price += ceil((total - fees[0]) / (double)fees[2]) * fees[3]; // (�������ð� - �⺻�ð�) / �ʰ��ð����� * �ʰ��ð����
        }

        answer.push_back(price);                                          // �̹� ���ĵǾ� ������ ��Ż������ �־��ָ� ��
    }

    return answer;
}


// REF : https://wadekang.tistory.com/8 //copyed from this blog
// REF : https://life-with-coding.tistory.com/403 // stringstream
// Key concept 
// sstream, map, cmath, ceil