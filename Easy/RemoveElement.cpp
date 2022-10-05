class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>a;
        for(string i:arr)a[i]++;
        for(string i:arr){
            if(a[i]==1){
                k--;
                if(k==0){
                    return i;
                }
             }
        }
        return "";
    }
};