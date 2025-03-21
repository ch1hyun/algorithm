#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// DP 정의 : DP[i] = (i번째 집을 털 때 모은 돈의 최대 값)
// DP 점화식 : DP[i] = max(DP[i - 2], DP[i - 3]) + money[i]
// 원의 형태이기 때문에 첫 집을 털었는지, 털지 않았는지에 따라 마지막 집의 포함 여부가 결정 -> 두 개를 동시에 돌림

int dp[4][1000000];

int solution(vector<int> money) {
    dp[0][0] = money[0];
    dp[0][1] = money[0];
    dp[0][2] = money[0];
    dp[1][0] = money[0];
    dp[1][1] = money[0];
    dp[1][2] = money[0] + money[2];
    dp[2][0] = 0;
    dp[2][1] = 0;
    dp[2][2] = money[1];
    dp[3][0] = 0;
    dp[3][1] = money[1];
    dp[3][2] = money[2];
    // 0 : 1 1 4 
    // 1 : 0 2 2 
    
    for (int i = 3; i < money.size() - 1; ++i) {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
        dp[1][i] = dp[0][i - 1] + money[i];
        dp[2][i] = max(dp[2][i - 1], dp[3][i - 1]);
        dp[3][i] = dp[2][i - 1] + money[i];
    }
    
    int lastIdx = money.size() - 1;
    if (money.size() > 3) {
        dp[0][lastIdx] = dp[1][lastIdx] = max(dp[0][lastIdx - 1], dp[1][lastIdx - 1]);
        dp[2][lastIdx] = max(dp[2][lastIdx - 1], dp[3][lastIdx - 1]);
        dp[3][lastIdx] = dp[2][lastIdx - 1] + money[lastIdx];
    }
    
    return max(max(dp[0][lastIdx], dp[1][lastIdx]), max(dp[2][lastIdx], dp[3][lastIdx]));
}