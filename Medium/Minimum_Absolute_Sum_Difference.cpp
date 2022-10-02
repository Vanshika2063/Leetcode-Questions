#include <bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2)
{
    int n=nums1.size();
    vector <int> diff(n);
    for(int i=0; i<n; i++)
        diff[i]=abs(nums1[i]-nums2[i]);                  //Store the differences in a vector

    sort(nums1.begin(), nums1.end());         //Sort the vector, so that we can apply binary search/lower bound

    int sub=0;
    for(int i=0; i<n; i++)
    {
        auto it=lower_bound(nums1.begin(), nums1.end(), nums2[i]);     //Find lower bound of nums2[i] in nums1
        int index=it-nums1.begin();
        int a, b, t;
        if(index==n)                    //IF the lower_bound of nums2[i] is not present in nums1 vector.
        {
            b=nums1[index-1];
            t=abs(b-nums2[i]);
        }
        else if(index==0)           //IF the lower_bound of nums2[i] is the first element in nums1 vector.
        {
            a=nums1[index];
            t=abs(a-nums2[i]);
        }
        else
        {
            a=nums1[index];
            b=nums1[index-1];
            t=min(abs(a-nums2[i]), abs(b-nums2[i]));       //Finding the smallest abs diff, i.e the closest to nums2[i] among a and b
        }
        sub=max(sub, diff[i]-t);          //Finding the greatest number we can substract to get minimum absolute sum difference.
    }

    long long int ans=-sub;            //Already subtracting the "sub" from our ans. (Due to mod being used later on, it is better to subtract it in the starting itself.
    for(int i=0; i<n; i++)
    {
        ans=(ans+diff[i])%mod;
    }

    ans=ans%mod;

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector <int> nums1(n), nums2(n);
    for(int i=0; i<n; i++)
        cin>>nums1[i];
    for(int i=0; i<n; i++)
        cin>>nums2[i];

    cout<<minAbsoluteSumDiff(nums1, nums2);
}
