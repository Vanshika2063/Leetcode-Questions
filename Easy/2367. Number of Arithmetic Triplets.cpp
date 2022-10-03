#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int res = 0;
        unordered_map<int, bool> m;
        for (auto &i : nums)
        {
            m[i] = true;
        }
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (m[nums[i] + diff] and m[nums[i] + (2 * diff)]) // find element present in hash map
                res++;
        }
        return res;
    }
};
