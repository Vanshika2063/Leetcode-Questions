/**
 * 1155. Number of Dice Rolls With Target Sum
 * <p>
 * You have d dice, and each die has f faces numbered 1, 2, ..., f.
 * Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to
 * roll the dice so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
 * <p>
 * Example 1:
 * Input: d = 1, f = 6, target = 3
 * Output: 1
 * Explanation:
 * You throw one die with 6 faces.  There is only one way to get a sum of 3.
 * <p>
 * Example 2:
 * Input: d = 2, f = 6, target = 7
 * Output: 6
 * Explanation:
 * You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
 * 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
 * <p>
 * Example 3:
 * Input: d = 2, f = 5, target = 10
 * Output: 1
 * Explanation:
 * You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
 * <p>
 * Example 4:
 * Input: d = 1, f = 2, target = 3
 * Output: 0
 * Explanation:
 * You throw one die with 2 faces.  There is no way to get a sum of 3.
 * <p>
 * Example 5:
 * Input: d = 30, f = 30, target = 500
 * Output: 222616187
 * Explanation:
 * The answer must be returned modulo 109 + 7.
 * <p>
 * Constraints:
 * 1 <= d, f <= 30
 * 1 <= target <= 1000
 */
class Solution {
    /**
     * Dynamic Programming approach solution
     *
     * @param n      number of dice
     * @param k      number of faces
     * @param target target sum
     * @return number of ways to get target sum
     */
    public int numRollsToTarget(int n, int k, int target) {
        // dp[i][j] = number of ways to get sum j using i dice
        int[][] dp = new int[n + 1][target + 1];
        // base case
        dp[0][0] = 1;
        // loop over dice
        for (int i = 1; i <= n; i++) {
            // loop over target sum
            for (int j = 1; j <= target; j++) {
                // loop over face values
                for (int l = 1; l <= k; l++) {
                    // if face value is less than target sum
                    if (j - l >= 0) {
                        // add number of ways to get target sum - face value using i - 1 dice
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % 1000000007;
                    }
                }
            }
        }
        // return number of ways to get target sum using n dice
        return dp[n][target];
    }
}
