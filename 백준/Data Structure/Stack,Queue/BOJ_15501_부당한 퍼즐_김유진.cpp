#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> arr;
vector<int> result;

int main()
{
	cin >> N;

	arr.resize(N);  // 벡터 사이즈 설정
	result.resize(N);

	for (int i = 0;i < N;i++)
	{
		cin >> arr[i];
	}

	int start_idx = 0;
	for (int i = 0;i < N;i++)
	{
		cin >> result[i];
		if (result[i] == arr[0])
			start_idx = i;   //첫번째 인덱스 어디인지 확인

	}
	
	// 뒤집지 않은 상태에서 원형으로 봤을 때 현재 배열과 동일한지 파악
	// 밀기만으로 정답
	bool same = true;
	for (int i = 0;i < N;i++)
	{
		if (arr[i] != result[(start_idx + i) % N])
		{
			same = false;
			break;
		}
	}

	if (same == true)
		cout << "good puzzle" << endl;
	else
	{
		// 뒤집기
		reverse(result.begin(), result.end());
		// 시작 인덱스 재설정
		start_idx = (N - 1) - start_idx;

		// 한번 뒤집은 후 원형으로 봤을 때 동일한지 파악
		same = true;
		for (int i = 0;i < N;i++)
		{
			if (arr[i] != result[(start_idx + i) % N])
			{
				same = false;
				break;
			}
		}
		
		if (same == true)
			cout << "good puzzle" << endl;
		else
			cout << "bad puzzle" << endl;
	}
	return 0;
}