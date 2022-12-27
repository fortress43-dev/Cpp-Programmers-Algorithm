#include <iostream>
#include <vector>

using namespace std;


// 전역변수 answer
int answer = 0;

void get_target_number(vector<int> numbers, int target, int sum, int index) {
    //종료 조건
    if (index == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        // 같지 않을때도 return
        return;
    }
    // 변하는 값을 업데이트하는 방법 - 전역변수선언 혹은 매개변수에 실는 것
    // 리스트의 각 요소는 +, - 해주는 두가지 경우의 수로 나뉜다
    get_target_number(numbers, target, sum + numbers[index], index + 1);
    get_target_number(numbers, target, sum - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    get_target_number(numbers, target, 0, 0);

    return answer;
}


int main()
{
    vector<int> numbers = { 1,1,1,1,1 };
    int target = 3;
    solution(numbers, target);

    std::cout << "answer : " << answer;
}



#pragma region my wrong code

/*

int i = 0;
int sum = 0;
int answer = 0;
void solution(vector<int> numbers, int target)
{
    if (i == numbers.size())
    {
        if (sum == target) {
            answer++;
            sum = 0;
            i = 0;
        }
        std::cout << "no answer";
        return;
    }
    sum += numbers[i];
    solution(numbers, target);
    i++;

}



int main()
{
    vector<int> numbers = { 1,1,1,1 };
    int target = 3;
    solution(numbers, target);

    std::cout << "answer : "<< answer;
}

*/


#pragma endregion
