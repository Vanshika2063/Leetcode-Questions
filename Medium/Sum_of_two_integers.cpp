//Problem Link - https://leetcode.com/problems/sum-of-two-integers/
/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = 2, b = 3
Output: 5

Constraints:
-1000 <= a, b <= 1000

*/

// Time-Complexity:-  -> O(1) constant as 32 is the number of bits at most we will have to bit shift until carry is zero.
// Space-Complexity:- O(1)


class Solution {
public:
    int getSum(int a, int b) {
        if(a==0 || b==0){
            return a^b;
        }
        return getSum(a^b , (unsigned(a&b) <<1));
    }
};
