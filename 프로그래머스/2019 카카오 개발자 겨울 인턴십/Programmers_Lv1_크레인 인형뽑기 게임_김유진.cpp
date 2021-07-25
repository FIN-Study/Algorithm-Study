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
        num = moves[i] - 1;  // 1부터 시작하면서 체크

        for(int j = 0; j < board.size();j++)  // x축(1차원은 계속 증가, 2차원은 고정)
        {
            // 0이 아닌 경우 인형 있음
            if (board[j][num] != 0)  
            {
                // stack의 제일 윗 인형과 넣어야 하는 인형이 같은 경우, 넣지 않음 & stack 젤 윗 인형 없앰.
                // 인형 2개 일치해서 없앴으므로, annswer 2 증가
                if (!stac.empty() && stac.top() == board[j][num])
                {
                    stac.pop();
                    answer += 2;
                }
                // 스택의 제일 윗 인형과 넣어야 할 인형이 다른 경우, 스택에 그 인형 넣음
                else
                {
                    stac.push(board[j][num]);
                }
                // 스택에 인형 넣으면, 해당 좌표에서 인형 없다. 0으로 바꿔줌.
                board[j][num] = 0;
                break;  // 좌표에서 제일 위에 있는 인형만 검사하는거니까, 더 깊게 안들어감
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