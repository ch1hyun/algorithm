
import java.util.Scanner;

//TIP 코드를 <b>실행</b>하려면 <shortcut actionId="Run"/>을(를) 누르거나
// 에디터 여백에 있는 <icon src="AllIcons.Actions.Execute"/> 아이콘을 클릭하세요.
class Solution {
    public int solution(int n, int m, int[] money) {
        int answer = 2000000000;

        int low = 1, high = 2000000000;

        while (low <= high) {
            int mid = (low + high) / 2;

            int count = 1;
            int cur = mid;
            boolean need_more_money = false;
            for (int i = 0; i < money.length; ++i) {
                if (cur < money[i]) {
                    ++count;
                    cur = mid;
                }

                if (cur < money[i]) {
                    need_more_money = true;
                    low = money[i];
                    break;
                }
                cur -= money[i];
            }

            if (need_more_money) {
                continue;
            }

            if (count <= m) {
                high = mid - 1;
                answer = Math.min(answer, mid);
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        int n, m;
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        int[] money = new int[n];
        for (int i = 0; i < n; ++i) {
            money[i] = sc.nextInt();
        }

        Solution solution = new Solution();
        System.out.println(solution.solution(n, m, money));
    }
}