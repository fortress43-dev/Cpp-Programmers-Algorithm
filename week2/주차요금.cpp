#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int time_diff(string in, string out) {        // 들어오고 나간 시간의 차이를 구하는 함수
    int h1 = stoi(in.substr(0, 2));           // stoi -> string to int
    int m1 = stoi(in.substr(3, 2));           // h : hour // m : minute
    int h2 = stoi(out.substr(0, 2));          // substr(0,2) -> index 0부터 2개 뽑음
    int m2 = stoi(out.substr(3, 2));

    int diff = (h2 - h1) * 60 + (m2 - m1);    // 시간을 분으로 바꿔줌 -> hour * 60 + minute 

    return diff;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> m;                                      // map은 key를 오름차순으로 자동정렬해준다 // 입출기록은 리스트로 받음
                                                                        
    stringstream ss;                                                    // stringstream은 띄워쓰기로 나눠진 str을 뽑아쓰기 좋다
    for (auto record : records) {                                       
        ss.str(record);                                                 // 작업을 위해 stringstream에 string을 넣어준다
        string time, number, status; ss >> time >> number >> status;    // 여러 string에 이런 식으로 넣을 수 있다

        m[number].push_back(time);                                      // map에 데이터를 넣어준다 -> key << carNumber , value << time 
        ss.clear();                                                     
    }

    for (auto it : m) {
        if (it.second.size() & 1) // 주차 내역 홀수면 "23:59" 추가
            it.second.push_back("23:59");

        vector<string> info = it.second;
        int total = 0;
        for (int i = 0; i < info.size() - 1; i += 2) {                  // 반복할 때 짝수번으로 진행해야 해서 마지막 idx까지 하면 안됨
            total += time_diff(info[i], info[i + 1]);                   // info에 여러개의 입출기록이 있어도 for문으로 처리
        }

        int price = fees[1];                                              // 기본요금은 무조건 부과
        if (total > fees[0]) {                                            // 총주차시간이 기본시간보다 크다면
            price += ceil((total - fees[0]) / (double)fees[2]) * fees[3]; // (총주차시간 - 기본시간) / 초과시간기준 * 초과시간요금
        }

        answer.push_back(price);                                          // 이미 정렬되어 있으니 토탈가격을 넣어주면 됨
    }

    return answer;
}


// REF : https://wadekang.tistory.com/8 //copyed from this blog
// REF : https://life-with-coding.tistory.com/403 // stringstream
// Key concept 
// sstream, map, cmath, ceil