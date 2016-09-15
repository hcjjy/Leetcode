/*
https://leetcode.com/problems/increasing-triplet-subsequence/
最长递增子序列的迷你版
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
        {
            return false;
        }
        vector<int>MaxLen;
        MaxLen.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); ++i)
        {
            int greater = lower_bound(MaxLen.begin(), MaxLen.end(), nums[i]) - MaxLen.begin();
            if(greater == MaxLen.size())
            {
                MaxLen.push_back(nums[i]);
                if(MaxLen.size() >= 3)
                {
                    return true;
                }
            }
            else
            {
                MaxLen[greater] = nums[i];
            }
        }
        return false;
    }
};
/*
就找长度至少为三而言的特殊解法
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int idx1 = INT_MAX, idx2 = INT_MAX;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] <= idx1)
            {
                idx1 = nums[i];
            }
            else if(nums[i] <= idx2)
            {
                idx2 = nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
