import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int answer = -1;
        
        List<Set<Integer>> dp = new ArrayList();
        
        for (int i = 0; i <= 8; ++i) {
            dp.add(new HashSet<>());
        }
        
        for (int i = 1; i <= 8; ++i) {
            int repeated = Integer.parseInt(String.valueOf(N).repeat(i));
            
            dp.get(i).add(repeated);
            
            for (int j = 1; j < i; ++j) {
                for (int a : dp.get(j)) {
                    for (int b : dp.get(i - j)) {
                        dp.get(i).add(a + b);
                        dp.get(i).add(a - b);
                        dp.get(i).add(b - a);
                        dp.get(i).add(a * b);
                        
                        if (a != 0) {
                            dp.get(i).add(b / a);
                        }
                        if (b != 0) {
                            dp.get(i).add(a / b);
                        }
                    }
                }
            }
            
            if (dp.get(i).contains(number)) {
                return i;
            }
        }
        
        return -1;
    }
}

/*
5
55 5+5 5-5 5*5 5/5
555 55+5 55-5 55*5 55/5 ... 5/5+5 5/5-5 5/5*5 5/5/5
5555 555+5 555-5 555*5 555/5 ... 5/5/5+5 5/5/5-5 ...

*/