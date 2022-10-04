// Leetcode solution to problem #1672
// Easy

// https://leetcode.com/problems/richest-customer-wealth/

// code

class RichestCustomerWealthSolution {
    public int maximumWealth(int[][] accounts) {
        int max=0;
    for(int i=0; i<accounts.length; i++){
      int sum=0;
      for(int j=0; j<accounts[i].length; j++){
        sum += accounts[i][j];
      }
      if(sum>max){
        max = sum;
      }
    }
    return max;
    }
}