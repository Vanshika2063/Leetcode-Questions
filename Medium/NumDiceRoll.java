public class NumDiceRoll {
    
    // 1155. Number of Dice Rolls With Target Sum
//     We will use DP here => recursion with memoisation
//     because two variables are changing here and we have to explore all the options
//     one is rolling turn changes and target acheived so far is changing
//     we will store it like dp[dice][targetSum] for memoisation
//     
public int numRollsToTarget(int n, int k, int target) {
    int[][] dp = new int[n+1][target+1];
    
    for(int[] arr:dp){
        Arrays.fill(arr,-1);
    }
    
    return dfs(n,k,target,dp);
}
private int dfs(int n,int k,int target,int[][] dp){
//         no way
    if(n<0 || target<0){
        return 0;
    }
//         found one way
    if(n==0 && target==0){
        return 1;
    }
//         memoisation
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
//         main logic
//         Total ways can be found at when from a particular dice roll we call dfs for all the face values that are available to us
//         we call for one less dice as one dice as n-1 is utilised in the current target as target-face value.
    int totalWays = 0;
    for(int i=1;i<=k;i++){
        totalWays = (totalWays+dfs(n-1,k,target-i,dp))%((int)1e9+7);
    }
//         At current dice role and target, these are the number of ways we have found.
    return dp[n][target] = totalWays;
}
}
