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

	arr.resize(N);  // ���� ������ ����
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
			start_idx = i;   //ù��° �ε��� ������� Ȯ��

	}
	
	// ������ ���� ���¿��� �������� ���� �� ���� �迭�� �������� �ľ�
	// �б⸸���� ����
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
		// ������
		reverse(result.begin(), result.end());
		// ���� �ε��� �缳��
		start_idx = (N - 1) - start_idx;

		// �ѹ� ������ �� �������� ���� �� �������� �ľ�
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