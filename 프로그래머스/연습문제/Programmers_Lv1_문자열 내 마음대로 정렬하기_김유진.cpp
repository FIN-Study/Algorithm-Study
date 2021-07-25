#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const pair<string, string>& a, const pair<string, string>& b)
{
    if (a.second != b.second)
        return a.second < b.second;  // 인덱스 알파벳 기준으로 정렬 
    else
        return a.first < b.first;    // 인덱스 알파벳이 같을 경우, string 전체를 기준으로 정렬

}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    vector<pair<string, string>> tmp;  // tmp 벡터 : (전체 스트링, 인덱스 알파벳)
    for (int i = 0;i < strings.size();i++)
    {
        tmp.push_back(make_pair(strings[i], strings[i].substr(n, 1)));
        // tmp.second : substr로 해당 인덱스의 알파벳 저장 
        // tmp.first : 그 인덱스에 해당하는 string 전체 저장
    }

    sort(tmp.begin(), tmp.end(), compare);
    // compare 함수 기준으로 정렬(인덱스 알파벳 기준 정렬 & 인덱스 알파벳 같으면 string 전체 기준 정렬)

    for (int i = 0;i < strings.size();i++)
    {
        answer.push_back(tmp[i].first);  // 정렬된 tmp의 first 전체 스트링이 답
    }

    return answer;
}