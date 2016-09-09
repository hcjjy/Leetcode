/*
https://leetcode.com/problems/maximum-subarray/
保存一个最大值变量，另外保存一个尝试着寻找最大值的变量，有动态规划的思想，
以下两种解法差不多，只不过第二个更简便一些。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValue = nums[0], attempt = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(maxValue <= 0 && maxValue < nums[i])
            {
                maxValue = nums[i];
                attempt = nums[i];
            }
            else if(maxValue > 0)
            {
                attempt += nums[i];
                if(attempt <= 0)
                {
                    attempt = 0;
                }
                if(attempt > maxValue)
                {
                    maxValue = attempt;
                }
            }
           
        }
        return maxValue;
    }
};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxVal = nums[0];
		int dp = nums[0];
		for(int i = 1; i < nums.size(); ++i)
		{
			dp = nums[i] + (dp > 0 ? dp : 0);
			maxVal = max(maxVal,dp);
		}
		return maxVal;
	}
};
