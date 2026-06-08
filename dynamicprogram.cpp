import java.util.*;

public class DynamicProgrammingRow {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        
        int numStates = 1 << n; 
        int[] dp = new int[numStates];
        
        Arrays.fill(dp, Integer.MIN_VALUE / 2);
        dp[0] = 0; 

        for (int mask = 0; mask < numStates; mask++) {
            if (dp[mask] == Integer.MIN_VALUE / 2) continue;

            int row = Integer.bitCount(mask);
            if (row == n) break; 

            for (int col = 0; col < n; col++) {
                if ((mask & (1 << col)) == 0) {
                    int nextMask = mask | (1 << col);
                    dp[nextMask] = Math.max(dp[nextMask], dp[mask] + a[row][col]);
                }
            }
        }

        System.out.println(dp[numStates - 1]);
        sc.close();
    }
}
