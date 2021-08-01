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
	int idx1 = 0;  // ���� ����
	int idx2 = 1;  // ������ �ι�°
	int idx3 = N - 1;  // ���� �Ʒ�

	for (int i = 0;i < N;i++)
	{
		if (arr[i] == 1) // ���1
		{
			result[idx1] = num;  // ���� ���� ��ġ
			if (result[idx1 + 1] == 0) // �� ���� ��ġ�� ���������
				idx1++;  // �� ������ ���� ���� ��
			else {
				idx1 = idx2 + 1; // �� ���� ��ġ�� �ڸ� ��������, idx2�� ������ �ι�° �� ���� ���� ���� ��
			}
		}
		else if (arr[i] == 2)  //���2
		{
			if (result[idx1 + 1] == 0) // idx1 + 1�� ���� ������ �ι�°
				idx2 = idx1 + 1;
			else  // ������ �ι�°�� �ڸ� ������ ���� �� ������ ������ �ι�°�� ��
				idx2 += 1;
			result[idx2] = num;  //������ �ι�° �ڸ��� num ����
		}
		else if (arr[i] == 3) // ���3
		{
			result[idx3] = num; // idx3 ���� �Ʒ��� num ����
			idx3 -= 1;
		}
		num -= 1;  // ��������
	}

	for (int i = 0;i < N;i++)
		cout << result[i] << " ";

	return 0;

}