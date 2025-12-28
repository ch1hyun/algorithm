import java.util.*;
import java.io.*;
// https://velog.io/@ryusuz/JAVA-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8%EC%9A%A9-%EC%A3%BC%EC%9A%94-%ED%95%A8%EC%88%98-%EB%AA%A8%EC%9D%8C

class Main {

    static int[] board = new int[100001];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static class Solution {
        public boolean isFirstValue(int x) {
            return board[x] == -1;
        }

        public boolean needToProcess(int from, int to) {
            return isFirstValue(to) || board[from] + 1 < board[to];
        }

        public void bfs(int c) throws IOException {
            Queue<Integer> q = new LinkedList<>();
            q.add(c);
            board[c] = 0;

            while (!q.isEmpty()) {
                int cur = q.poll();
                if (cur > 0 && needToProcess(cur, cur - 1)) {
                    board[cur - 1] = board[cur] + 1;
                    q.add(cur - 1);
                }

                if (cur < 100000 && needToProcess(cur, cur + 1)) {
                    board[cur + 1] = board[cur] + 1;
                    q.add(cur + 1);
                }

                if (cur != 0 && cur <= 50000 && needToProcess(cur, cur * 2)) {
                    board[cur * 2] = board[cur] + 1;
                    q.add(cur * 2);
                }
            }

        }
    }


    public static void main(String[] args) throws IOException {
        Arrays.fill(board, -1);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        Solution solution = new Solution();
        solution.bfs(n);
        bw.write(board[k] + "\n");
        bw.flush();
        bw.close();
    }
}
