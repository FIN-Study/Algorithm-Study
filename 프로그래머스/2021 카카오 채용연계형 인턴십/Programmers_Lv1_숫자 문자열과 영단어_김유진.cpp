#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    //int answer = 0;
    string answer = "";

    for (int i = 0; i < s.size();i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            answer += s[i];
        else
        {
            if (s[i] == 'z') {
                answer += "0";
                i = i + 3;
            }

            else if (s[i] == 'o') {
                answer += "1";
                i += 2;
            }
            else if (s[i] == 't') {
                if (s.substr(i, 3) == "two") {
                    answer += "2";
                    i += 2;
                }

                else {
                    answer += "3";
                    i += 4;
                }
            }
            else if (s[i] == 'f') {
                if (s.substr(i, 4) == "four") {
                    answer += "4";
                    i += 3;
                }

                else {
                    answer += '5';
                    i += 3;
                }
            }
            else if (s[i] == 's') {
                if (s.substr(i, 3) == "six") {
                    answer += '6';
                    i += 2;
                }

                else {
                    answer += '7';
                    i += 4;
                }
            }
            else if (s[i] == 'e') {
                answer += '8';
                i += 4;
            }

            else if (s[i] == 'n') {
                answer += '9';
                i += 3;
            }

        }
    }


    // cout << s;
    // string one = "one";
    // s.replace(s.find(one),one.length(),"1");
    // s.replace(s.find("zero"),4,"0");
    // s.replace(s.find("one"),3,"1");
    // s.replace(s.find("two"),3,"2");
    // s.replace(s.find("three"),5,"3");
    // s.replace(s.find("four"),4,"4");
    // s.replace(s.find("five"),4,"5");
    // s.replace(s.find("six"),3,"6");
    // s.replace(s.find("seven"),5,"7");
    // s.replace(s.find("eight"),5,"8");
    // s.replace(s.find("nine"),4,"9");

    //answer = stringstream ssInt(s);
    //answer = stoi(s);
    //cout << s;

    return stoi(answer);
}