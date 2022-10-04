/*
2429. Minimize XOR

Given two positive integers num1 and num2, find the integer x such that:

    x has the same number of set bits as num2, and
    The value x XOR num1 is minimal.

Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

 

Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.

 

Constraints:

    1 <= num1, num2 <= 10^9
*/

class Solution {
public:
    int minimizeXor(int n1, int n2) {
        int cnt = 0;
        for(int i = 0;i < 32;i++){
            if((n2 >> i) & 1){
                cnt++;
            }
        }
        int ans = 0;
        for(int i = 31;i >= 0 and cnt > 0;i--){
            if((n1 >> i) & 1){
                cnt--;
                ans |= (1 << i);
            }
        }
        int i = 0;
        while(cnt > 0 and i < 32){
            if(((n1 >> i) & 1) == 0){
                cnt--;
                ans |= (1 << i);
            }
            i++;
        }
        return ans;
    }
};