#include<string>
#include <iostream>

using namespace std;
int openCnt = 0;

bool solution(string s)
{
    for (char c : s) {
        if (c == '(') {
            ++openCnt;
        } else {
            if (!openCnt) return false;
            --openCnt;
        }
    }
    
    if (openCnt) return false;
    return true;
}