
import java.util.*;

//TIP 코드를 <b>실행</b>하려면 <shortcut actionId="Run"/>을(를) 누르거나
// 에디터 여백에 있는 <icon src="AllIcons.Actions.Execute"/> 아이콘을 클릭하세요.
class Solution {

    public static class Tuple {
        int a;
        int b;
        int c;

        public Tuple(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public boolean equals(Object obj) {
            if (!(obj instanceof Tuple)) return false;
            Tuple that = (Tuple) obj;
            return a == that.a && b == that.b && c == that.c;
        }

        @Override
        public int hashCode() {
            return Objects.hashCode(a) + Objects.hashCode(b) + Objects.hashCode(c);
        }
    }

    public Map<Tuple, Integer> tupleset = new HashMap();

    public int w(int a, int b, int c) {
        if (tupleset.containsKey(new Tuple(a, b, c))) {
            return tupleset.get(new Tuple(a, b, c));
        }

        if (a <= 0 || b <= 0 || c <= 0) {
            tupleset.put(new Tuple(a, b, c), 1);
            return 1;
        }

        if (a > 20 || b > 20 || c > 20) {
            int ret = w(20, 20, 20);
            tupleset.put(new Tuple(a, b, c), ret);
            return ret;
        }

        if (a < b && b < c) {
            int ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
            tupleset.put(new Tuple(a, b, c), ret);
            return ret;
        }

        int ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        tupleset.put(new Tuple(a, b, c), ret);
        return ret;
    }

    public int solution(List<Tuple> tuples) {
        for (Tuple tuple : tuples) {
            System.out.println("w(" + tuple.a + ", " + tuple.b + ", " + tuple.c + ") = " + w(tuple.a, tuple.b, tuple.c));
        }
        return 0;
    }
}
public class Main {
    public static void main(String[] args) {
        List<Solution.Tuple> tuples = new ArrayList<>();

        Scanner sc = new Scanner(System.in);

        while (true) {
            int a, b, c;
            a = sc.nextInt(); b = sc.nextInt(); c = sc.nextInt();
            if (a == -1 && b == -1 && c == -1) break;
            tuples.add(new Solution.Tuple(a, b, c));
        }

        Solution solution = new Solution();
        solution.solution(tuples);
    }
}