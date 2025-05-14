
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

//TIP 코드를 <b>실행</b>하려면 <shortcut actionId="Run"/>을(를) 누르거나
// 에디터 여백에 있는 <icon src="AllIcons.Actions.Execute"/> 아이콘을 클릭하세요.
public class Main {
    static Set<Integer> map = new HashSet<>();
    static int n;
    static List<Integer> xs = new ArrayList<>();
    static int count = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            xs.add(sc.nextInt());
        }

        Collections.sort(xs);
        int i,j;

        for (int z = 0; z < n; ++z) {
            i = 0;
            j = n - 1;
            int cur = xs.get(z);
            while (i < j) {
                if (i == z) ++i;
                if (j == z) --j;
                
                if (i >= j) break;
                
                int sum = xs.get(i) + xs.get(j);
                if (sum > cur) {
                    --j;
                } else if (sum < cur) {
                    ++i;
                } else {
                    ++count;
                    break;
                }
            }
        }

        System.out.println(count);
    }
}