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
		// num의 1의 자리수가 result의 10의 자리수
		// 더한 값의 1의 자리수는 result의 1의 자리수
		num = (num % 10) * 10 + ((num / 10) + (num % 10) % 10);
		cnt++;
	} while (num != res);

	cout << cnt;
	return 0;
}