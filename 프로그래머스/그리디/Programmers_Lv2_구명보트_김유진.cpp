#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    int idx = 0; // �������� ������ �ε���
    int weight = 0;  // ���� ���ſ� ��� ������ ���� ����

    sort(people.begin(), people.end());

    while (idx < people.size())
    {
        int weight = people.back(); // ���� ���ſ� ��� ������ ����
        people.pop_back(); // ���� ���ſ� ��� ����
        // ����Ʈ�� �ִ� 2�� Ż �� ����
        // ���� �������� + ���� ���ſ��� <= limit    -> 2�� ž��
        if (people[idx] + weight <= limit) {
            answer += 1;
            idx += 1;    // idx�� 1 �Űܼ�, 2���� �� ����Ʈ�� Ÿ���� ī����        
        }
        // ���� �������� + ���� ���ſ��� > limit     -> 1�� ž��
        else {
            answer += 1;
        }
    }
    return answer;
}