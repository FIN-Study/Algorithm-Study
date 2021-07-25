#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stac;
    int num = 0;

    for (int i = 0; i < moves.size();i++)
    {
        //num = board[moves[i]-1].back();
        num = moves[i] - 1;  // 1���� �����ϸ鼭 üũ

        for(int j = 0; j < board.size();j++)  // x��(1������ ��� ����, 2������ ����)
        {
            // 0�� �ƴ� ��� ���� ����
            if (board[j][num] != 0)  
            {
                // stack�� ���� �� ������ �־�� �ϴ� ������ ���� ���, ���� ���� & stack �� �� ���� ����.
                // ���� 2�� ��ġ�ؼ� �������Ƿ�, annswer 2 ����
                if (!stac.empty() && stac.top() == board[j][num])
                {
                    stac.pop();
                    answer += 2;
                }
                // ������ ���� �� ������ �־�� �� ������ �ٸ� ���, ���ÿ� �� ���� ����
                else
                {
                    stac.push(board[j][num]);
                }
                // ���ÿ� ���� ������, �ش� ��ǥ���� ���� ����. 0���� �ٲ���.
                board[j][num] = 0;
                break;  // ��ǥ���� ���� ���� �ִ� ������ �˻��ϴ°Ŵϱ�, �� ��� �ȵ�
            }
        }
    }



    return answer;
}

int main()
{
    vector<vector<int>> board;
    vector<int> moves;
    int answer;
    board = { {0,0,0,0,0 }, { 0,0,1,0,3 }, { 0,2,5,0,1 }, { 4,2,4,4,2 }, { 3,5,1,3,1 } };
    moves = { 1,5,3,5,1,2,1,4 };
    answer = solution(board, moves);
    cout << answer;
}