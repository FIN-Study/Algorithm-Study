#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
void dfs(int index, int sum, int target, vector<int> numbers)
{
    if (index == numbers.size()) {  //numbers의 마지막 원소까지 간 경우
        if (sum == target) {  // sum이 target과 같으면
            answer++;
        }
        return;
    }
    dfs(index + 1, sum + numbers[index], target, numbers); // 더하는 쪽으로 재귀
    dfs(index + 1, sum - numbers[index], target, numbers); // 빼는 쪽으로
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);

    return answer;
}