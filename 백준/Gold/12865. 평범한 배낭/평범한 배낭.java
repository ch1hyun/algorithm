
import java.util.*;

//TIP 코드를 <b>실행</b>하려면 <shortcut actionId="Run"/>을(를) 누르거나
// 에디터 여백에 있는 <icon src="AllIcons.Actions.Execute"/> 아이콘을 클릭하세요.
class Solution {
    public static class Bag implements Comparable<Bag> {
        public int first;
        public int second;

        public Bag(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Bag that) {
            if (first > that.first) return 1;
            else if (first < that.first) return -1;

            if (second > that.second) return 1;
            else if (second < that.second) return -1;

            return 0;
        }
    }

    public int solution(int n, int k, List<Bag> bags) {
        int[] value = new int[k + 1];
        Arrays.fill(value, 0);

        for (int i = 0; i < bags.size(); ++i) {
            int curW = bags.get(i).first, curV = bags.get(i).second;
            for (int j = k; j >= curW; --j) {
                value[j] = Math.max(value[j], value[j - curW] + curV);
            }
        }

        return value[k];
    }
}
public class Main {
    public static void main(String[] args) {
        int n, m;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); m = sc.nextInt();

        List<Solution.Bag> bags = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            int x, y;
            x = sc.nextInt();y = sc.nextInt();
            bags.add(new Solution.Bag(x, y));
        }

        Solution solution = new Solution();
        System.out.println(solution.solution(n, m, bags));
    }
}