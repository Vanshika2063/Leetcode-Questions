class Solution {
public:
    int ncr(int n,int r)
    {   int res=1;
        for(int i=0;i<r;i++)
        {
            res=res*(n-i);
            res=res/(i+1);
        }
     return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++)
        {   
            vector<int>temp;
            
            for(int j=0;j<=i;j++)
            {
                temp.push_back(ncr(i,j));    
            }
            ans.push_back(temp);
        }
        return ans;
    }
};