/*
https://leetcode.com/problems/longest-increasing-subsequence/
参考网站：http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html
思路：
从最后一个开始更新每个结点的最长递增序列
*/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if(0 == n)
			return 0;
		vector<int>vecLen(n,1);
		for(int i = n - 1;i >= 0; --i)
		{
			int max = vecLen[i];
			for(int j = i + 1;j < n; ++j)
			{
				if(nums[i] < nums[j] && max < vecLen[i] + vecLen[j])
				{
					max = vecLen[i] + vecLen[j];
				}
			}
			vecLen[i] = max;
		}
		int ret = 0;
		for(int i = 0; i < n; ++i)
		{
			if(vecLen[i] > ret)
			{
				ret = vecLen[i];
			}
		}
		return ret;
	}
};

/*
每个长度中最后一个数为最小值(贪心)
*/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums){
		int n = nums.size();
		if(0 == n)
		{
			return 0;
		}
		vector<int>vecMaxLenMinNum(n, -1);
		vecMaxLenMinNum[0] = nums[0];
		int realLen = 1;
		for(int i = 1; i < n; ++i)
		{
			int low = 0;
			int high = realLen;
			bool flag = false;
			while(low < high)
			{
				int mid = (low + high)/2;
				if(nums[i] == vecMaxLenMinNum[mid])
				{
					flag = true;
					break;
				}
				if(nums[i] < vecMaxLenMinNum[mid])
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			if(low == realLen)//所有的数据都比nums[i]小，更新最大长度
			{
				vecMaxLenMinNum[realLen++] = nums[i];
			}
			else if(!flag)//更新最小值
			{
				if(nums[i] < vecMaxLenMinNum[low])
					vecMaxLenMinNum[low] = nums[i];
				else
					vecMaxLenMinNum[low + 1] = nums[i];
			}
		}
		return realLen;
	}
};











