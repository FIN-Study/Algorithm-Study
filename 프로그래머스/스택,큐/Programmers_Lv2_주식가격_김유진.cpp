#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> stac;


    for (int i = 0; i < size;i++)
    {
        //������ ��������ʰ�, ���� ������ ���� ���簪���� ũ�ٸ� -> ������ �������ٸ�
        while (!stac.empty() && prices[stac.top()] > prices[i])
        {
            //���� ���������Ƿ�, i-���� �������� ����
            answer[stac.top()] = i - stac.top();
            //�� ����
            stac.pop();
            //�ݺ����� ���� : ������ ���� ���� �����Ǿ��� ���
            //���� ������ ��� �����Ƿ� 1�� ���̾� �־��ֱ� ���ؼ�            
        }
        //���� �ε����� ���ÿ� �ֱ�
        stac.push(i);

    }
    // ������ �������� �ݺ�
    while (!stac.empty())
    {
        //������ Ư�� ��ġ�� �̹� ���� �־����Ƿ� pushback�̳� insert�� �ϸ� X
        // �ڿ������� �־���ϹǷ� size-1���� top���� ����.
        answer[stac.top()] = size - stac.top() - 1;
        stac.pop();

    }


    return answer;
}