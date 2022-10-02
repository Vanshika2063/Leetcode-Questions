public class DecodeWays {
    
// 91. Decode Ways
// TC O(n) SC O(n)
// In this we will consider the numbers individually and last two as a group
//     when we are considering individually then current ways at i = ways at i-1
// when we are considering in group then current ways at i = ways at i-2
//     considering all the edge cases do a dry run on "11106"
public int numDecodings(String s) {
    if(s.charAt(0) == '0'){
        return 0;
    }
    int n = s.length();
    int[] dp = new int[n];
    dp[0] = 1;
    for(int i=1;i<n;i++){
        int ones = s.charAt(i) - '0';
        int tens = s.charAt(i-1) - '0';
        
        if(ones == 0 && tens!=1 && tens!=2){ //12402
            return 0;
        }
        int num = (tens*10)+ones;
        if(num>=10 && num<=26){
            if(i>=2){
                dp[i] += dp[i-2];
            }
            else{
                dp[i] += 1;
            }
        }
        
        if(num!=10 && num!=20){
            dp[i] += dp[i-1];
        }
    }
    return dp[n-1];
}

}
