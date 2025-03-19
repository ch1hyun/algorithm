#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getIdx(vector<int> &arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int solution(vector<int> stones, int k) {
    int answer = 210000000;
    vector<int> tmp;
    
    for (int i = 0; i < k; ++i) {
        tmp.push_back(stones[i]);
    }
    
    sort(tmp.begin(), tmp.end());
    
    answer = tmp[tmp.size() - 1];
    
    for (int i = k; i < stones.size(); ++i) {
        tmp.erase(tmp.begin() + getIdx(tmp, stones[i - k]));
        tmp.insert(tmp.begin() + getIdx(tmp, stones[i]), stones[i]);
        answer = min(answer, tmp[tmp.size() - 1]);
    }
    
    return answer;
}