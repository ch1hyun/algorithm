#include <string>
#include <vector>

using namespace std;

string erase0(string target) {
    string ret = "";
    for (char c : target) {
        if (c == '1') ret += c;
    }
    return ret;
}

string convertToBi(int length) {
    string ret = "";
    
    int limit = 1;
    int cnt = 0;
    for (; limit <= length; limit *= 2, ++cnt) {}
    limit /= 2; --cnt;
    
    while (cnt >= 0) {
        if (length >= limit) {
            length -= limit;
            ret += "1";
        } else {
            ret += "0";
        }
        
        limit /= 2; --cnt;
    }
    
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroCnt = 0;
    int roundCnt = 0;
    
    while (s != "1") {
        ++roundCnt;
        string nxt = erase0(s);
        zeroCnt += s.length() - nxt.length();
        s = convertToBi(nxt.length());
    }
    
    answer.push_back(roundCnt);
    answer.push_back(zeroCnt);
    
    return answer;
}