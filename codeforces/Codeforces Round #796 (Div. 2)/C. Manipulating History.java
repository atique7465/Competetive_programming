import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        int t, n;
        String str;
        FastReader scr = new FastReader();
        t = scr.nextInt();
        while (t-- > 0) {
            char ch = 0;
            n = scr.nextInt();
            n = (2 * n) + 1;
            while (n-- > 0) {
                str = scr.nextLine();
                int ln = str.length();
                for (int k = 0; k < ln; k++) {
                    ch ^= str.charAt(k);
                }
            }

            System.out.println(ch);
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] ria(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = Integer.parseInt(next());
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        long[] rla(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = Long.parseLong(next());
            return a;
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}