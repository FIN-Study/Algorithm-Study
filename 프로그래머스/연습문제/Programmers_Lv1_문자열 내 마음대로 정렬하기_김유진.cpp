#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const pair<string, string>& a, const pair<string, string>& b)
{
    if (a.second != b.second)
        return a.second < b.second;  // �ε��� ���ĺ� �������� ���� 
    else
        return a.first < b.first;    // �ε��� ���ĺ��� ���� ���, string ��ü�� �������� ����

}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    vector<pair<string, string>> tmp;  // tmp ���� : (��ü ��Ʈ��, �ε��� ���ĺ�)
    for (int i = 0;i < strings.size();i++)
    {
        tmp.push_back(make_pair(strings[i], strings[i].substr(n, 1)));
        // tmp.second : substr�� �ش� �ε����� ���ĺ� ���� 
        // tmp.first : �� �ε����� �ش��ϴ� string ��ü ����
    }

    sort(tmp.begin(), tmp.end(), compare);
    // compare �Լ� �������� ����(�ε��� ���ĺ� ���� ���� & �ε��� ���ĺ� ������ string ��ü ���� ����)

    for (int i = 0;i < strings.size();i++)
    {
        answer.push_back(tmp[i].first);  // ���ĵ� tmp�� first ��ü ��Ʈ���� ��
    }

    return answer;
}