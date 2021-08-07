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

	long long greedy = 1000000000; // max�� 10��9�º��� ũ�Ƿ� long long
	long long sum = 0;

	for (int i = 0;i < N-1;i++)
	{
		if (city[i] < greedy)   
			greedy = city[i]; // greedy�� ���ο� �ֿ�ҿ� ������ ������ ������ �����ҵ� ���� ���� �� �⸧�� ����
		sum += greedy * dist[i];  // ���ݱ��� �߿��� ���� �� �⸧�� X �� ���� �ֿ�ұ����� �Ÿ�  => ���� �����ұ��� ���� �ּ� ���
	}
	cout << sum;
	return 0;
}