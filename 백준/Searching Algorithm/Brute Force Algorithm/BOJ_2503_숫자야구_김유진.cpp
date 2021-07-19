//2503 : 숫자야구
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int num, number;
    int strike, ball;
    bool arr[1000]; // 1~999까지 처음엔 true라고 가정한 후, 될 숫자들을 false로 바꿈
    int strike_cnt, ball_cnt, cnt;
    string tmp, one, two;

    cin >> num;
    memset(arr, true, sizeof(arr)); // 처음에 모두 될 가능성이 있으므로 true로 초기화
    for (int i = 123;i <= 999;i++) // 3자리 숫자는 서로 다른 숫자이므로 123부터 시작
    {
        tmp = to_string(i); //i를 int->string
        if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
            arr[i] = false;  // 같은 수가 있으면 그 수는 false
        if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0)
            arr[i] = false;  // 0이 들어가있으면 그 수는 false
    }

    for (int j = 1; j <= num; j++) // 입력받으면서 true/false 정하기
    {
        cin >> number >> strike >> ball;
        for (int j = 123; j <= 999; j++)  // arr의 모든 숫자 돌면서 true/false 판단
        {
            strike_cnt = 0;  
            ball_cnt = 0;
            if (arr[j] == true) //arr에서 가능성 있는 수만 가지고 판단
            {
                one = to_string(number); //입력받은 숫자를 int->string
                two = to_string(j); // 가능성 있는 수를 int->string
                for (int x = 0; x < 3;x++) // 100, 10, 1의 자리를 돌면서 판단 // x,y는 자리수
                {
                    for (int y = 0; y < 3;y++)
                    {
                        if (x == y && one[x] == two[y]) //strike인 경우에는 자리수도 같고 숫자도 같음
                            strike_cnt++;
                        if (x != y && one[x] == two[y]) //ball인 경우에는 숫자만 같고 자리가 다름
                            ball_cnt++; 
                    }
                }
                if (strike_cnt != strike || ball_cnt != ball) //정답과 다른 숫자는 false로 바꿈
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