#include <string>
#include <vector>

using namespace std;

// global variable
int answer = 0;

void get_target_number(vector<int> numbers, int target, int sum, int index) {
    // end condition
    if (index == numbers.size()) {
        if (sum == target)
            answer++;
        // if it reached end : return
        return;
    }
    // recursive code is divided with to brunch
    // first : + number[index]
    // second : - number[index]

    // elements of list have two cases on one
    // therefore this recursive code can find all cases 
    get_target_number(numbers, target, sum + numbers[index], index + 1);
    get_target_number(numbers, target, sum - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    get_target_number(numbers, target, 0, 0);
    return answer;
}