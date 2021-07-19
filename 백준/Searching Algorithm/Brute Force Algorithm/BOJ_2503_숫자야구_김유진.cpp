//2503 : ���ھ߱�
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int num, number;
    int strike, ball;
    bool arr[1000]; // 1~999���� ó���� true��� ������ ��, �� ���ڵ��� false�� �ٲ�
    int strike_cnt, ball_cnt, cnt;
    string tmp, one, two;

    cin >> num;
    memset(arr, true, sizeof(arr)); // ó���� ��� �� ���ɼ��� �����Ƿ� true�� �ʱ�ȭ
    for (int i = 123;i <= 999;i++) // 3�ڸ� ���ڴ� ���� �ٸ� �����̹Ƿ� 123���� ����
    {
        tmp = to_string(i); //i�� int->string
        if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
            arr[i] = false;  // ���� ���� ������ �� ���� false
        if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0)
            arr[i] = false;  // 0�� �������� �� ���� false
    }

    for (int j = 1; j <= num; j++) // �Է¹����鼭 true/false ���ϱ�
    {
        cin >> number >> strike >> ball;
        for (int j = 123; j <= 999; j++)  // arr�� ��� ���� ���鼭 true/false �Ǵ�
        {
            strike_cnt = 0;  
            ball_cnt = 0;
            if (arr[j] == true) //arr���� ���ɼ� �ִ� ���� ������ �Ǵ�
            {
                one = to_string(number); //�Է¹��� ���ڸ� int->string
                two = to_string(j); // ���ɼ� �ִ� ���� int->string
                for (int x = 0; x < 3;x++) // 100, 10, 1�� �ڸ��� ���鼭 �Ǵ� // x,y�� �ڸ���
                {
                    for (int y = 0; y < 3;y++)
                    {
                        if (x == y && one[x] == two[y]) //strike�� ��쿡�� �ڸ����� ���� ���ڵ� ����
                            strike_cnt++;
                        if (x != y && one[x] == two[y]) //ball�� ��쿡�� ���ڸ� ���� �ڸ��� �ٸ�
                            ball_cnt++; 
                    }
                }
                if (strike_cnt != strike || ball_cnt != ball) //����� �ٸ� ���ڴ� false�� �ٲ�
                    arr[j] = false;
            }
        }
    }
    for (int i = 123; i <= 999; i++)
    {
        if (arr[i] == true)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}