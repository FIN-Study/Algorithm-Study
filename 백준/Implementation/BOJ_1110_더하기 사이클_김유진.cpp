#include <iostream>
using namespace std;

int main()
{
	int num;
	int cnt = 0;

	cin >> num;
	int res = 0;
	res = num;

	do {
		// num�� 1�� �ڸ����� result�� 10�� �ڸ���
		// ���� ���� 1�� �ڸ����� result�� 1�� �ڸ���
		num = (num % 10) * 10 + ((num / 10) + (num % 10) % 10);
		cnt++;
	} while (num != res);

	cout << cnt;
	return 0;
}