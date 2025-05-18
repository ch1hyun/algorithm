import java.util.*;

class Solution {
    int[][] minDp;
    int[][] maxDp;
    int[] operators;
    int numLen;
    
    int calculate(int s, int e, int op) {
        if (op == 1 && maxDp[s][e] != -1000000) {
            return maxDp[s][e];
        }
        if (op == -1 && minDp[s][e] != 1000000) {
            return minDp[s][e];
        }
        
        for (int i = 0; i < e - s; ++i) {
            if (op == 1) maxDp[s][e] = Math.max(maxDp[s][e], calculate(s, s + i, 1) + operators[s + i] * calculate(s + i + 1, e, operators[s + i]));
            if (op == -1) minDp[s][e] = Math.min(minDp[s][e], calculate(s, s + i, -1) + operators[s + i] * calculate(s + i + 1, e, operators[s + i]));
        }
        
        if (op == 1) {
            return maxDp[s][e];
        }
        return minDp[s][e];
    }
    
    public int solution(String arr[]) {
        numLen = arr.length / 2 + 1;
        minDp = new int[numLen][numLen];
        maxDp = new int[numLen][numLen];
        for (int i = 0; i < numLen; ++i) {
            Arrays.fill(minDp[i], 1000000);
            Arrays.fill(maxDp[i], -1000000);
        }
            
        for (int i = 0; i < numLen; ++i) {
            minDp[i][i] = Integer.parseInt(arr[2*i]);
            maxDp[i][i] = Integer.parseInt(arr[2*i]);
        }
        
        operators = new int[numLen - 1];
        for (int i = 0; i < operators.length; ++i) {
            if (arr[2*i + 1].equals("+")) {
                operators[i] = 1;
            } else {
                operators[i] = -1;
            }
        }
    
        return calculate(0, numLen - 1, 1);
    }
}

/*
dp(1, 3) = max(dp(1, 2) + 연산자 * num[3], 연산자 * num[1] + dp(2, 3));
dp(1, 5) = max(dp(1, 1) + num[2] + dp(3, 5), dp(1, 2) + num[3] + dp(4, 5), dp(1, 3) + num[4] + dp(5, 5));
*/