#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
int arr[1000001] = { 0, };
int result[1000001] = { 0, };

int main()
{
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> arr[i];
	}

	int num = N;
	int idx1 = 0;  // 제일 위에
	int idx2 = 1;  // 위에서 두번째
	int idx3 = N - 1;  // 제일 아래

	for (int i = 0;i < N;i++)
	{
		if (arr[i] == 1) // 기술1
		{
			result[idx1] = num;  // 제일 위에 위치
			if (result[idx1 + 1] == 0) // 그 다음 위치가 비어있을때
				idx1++;  // 그 다음이 제일 위가 됨
			else {
				idx1 = idx2 + 1; // 그 다음 위치에 자리 차있으면, idx2인 위에서 두번째 그 위가 제일 위가 됨
			}
		}
		else if (arr[i] == 2)  //기술2
		{
			if (result[idx1 + 1] == 0) // idx1 + 1이 제일 위에서 두번째
				idx2 = idx1 + 1;
			else  // 위에서 두번째에 자리 차있을 때는 그 다음이 위에서 두번째가 됨
				idx2 += 1;
			result[idx2] = num;  //위에서 두번째 자리에 num 삽입
		}
		else if (arr[i] == 3) // 기술3
		{
			result[idx3] = num; // idx3 제일 아래에 num 삽입
			idx3 -= 1;
		}
		num -= 1;  // 내림차순
	}

	for (int i = 0;i < N;i++)
		cout << result[i] << " ";

	return 0;

}