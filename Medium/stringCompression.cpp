/*

Problem Link:
https://leetcode.com/problems/string-compression/

*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int ansIndex = 0;
        int i = 0;
        
        while(i < n) {
            int j = i+1;
            // If adjacent elements are same, increment count of that element 
            while(j < n && chars[i] == chars[j]) {
                j++;
            }
            
            /*
            Will reach at this point if traversed whole char vector
            or if encounter a new/different character
            */
            
            // Storing old character in modified chars array 
            chars[ansIndex++] = chars[i];
            
            // Gives count of a particular character
            int count = j-i;
            
            // If count > 1, converting count into single 
            // digit and saving in modified chars array 
            if(count > 1) {
                string cnt = to_string(count);
                for(char ch : cnt) {
                    chars[ansIndex++] = ch;
                }
            } 
            
            // Making i = j for counting next new/different character 
            i = j;
        }
        
        // ansIndex store length of modified chars array
        return ansIndex;
    }
};
