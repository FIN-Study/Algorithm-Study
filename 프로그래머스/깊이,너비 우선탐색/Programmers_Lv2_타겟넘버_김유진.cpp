#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
void dfs(int index, int sum, int target, vector<int> numbers)
{
    if (index == numbers.size()) {  //numbers�� ������ ���ұ��� �� ���
        if (sum == target) {  // sum�� target�� ������
            answer++;
        }
        return;
    }
    dfs(index + 1, sum + numbers[index], target, numbers); // ���ϴ� ������ ���
    dfs(index + 1, sum - numbers[index], target, numbers); // ���� ������
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);

    return answer;
}