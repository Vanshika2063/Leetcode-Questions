class Solution {
public:
    void solve(vector<int>input,vector<int>output,set<vector<int>> &ans){
    //base-case
    if(input.size()==0){
        ans.insert(output);
        return;
    }
    //recursive call 
    int x=input[0];
    input.erase(input.begin()+0);
        solve(input,output,ans);
    output.push_back(x);
    solve(input,output,ans);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>output;set<vector<int>>ans;sort(nums.begin(),nums.end());
        solve(nums,output,ans);
        vector<vector<int>>ans1;
        for(auto i:ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};
