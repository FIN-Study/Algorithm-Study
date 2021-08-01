#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long dist[100001];
long long city[100001];
long long N;

int main()
{
	cin >> N;

	for (int i = 0;i < N-1;i++)
	{
		cin >> dist[i];
	}
	for (int i = 0;i < N;i++)
	{
		cin >> city[i];
	}

	long long greedy = 1000000000; // max가 10의9승보다 크므로 long long
	long long sum = 0;

	for (int i = 0;i < N-1;i++)
	{
		if (city[i] < greedy)   
			greedy = city[i]; // greedy에 새로운 주요소에 도착할 때마다 지나온 주유소들 중의 제일 싼 기름값 저장
		sum += greedy * dist[i];  // 지금까지 중에서 제일 싼 기름값 X 그 다음 주요소까지의 거리  => 다음 주유소까지 가는 최소 비용
	}
	cout << sum;
	return 0;
}