#include <iostream>
using namespace std;

int num;
int cnt = 0;
int arr[101];

int main()
{	
	cin >> num;

	for (int i = 0;i < num;i++)
		cin >> arr[i];

	// 이전 값이 현재 값보다 더 크면 1씩 계속 빼주고 count
	for (int i = num - 1;i >= 1;i--)
	{
		while (arr[i] < arr[i + 1]) {
			arr[i - 1] -= 1;
			cnt++;
		}
	}
	cout << cnt;
}