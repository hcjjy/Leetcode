/*
https://leetcode.com/problems/find-peak-element/
直接遍历找到第一个峰值
*/
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if(nums.size() == 1)
		{
			return 0;
		}
		int cmp = nums[0];
		for(int i = 1; i < nums.size(); ++i)
		{
			if(cmp > nums[i])
			{
				return i- 1;
			}
			else
			{
				cmp = nums[i];
			}
		}
		return nums.size() - 1;
	}
};

/*模拟二分查找，找到一个最大值必定是峰值(注意有一个细节成就了最大值必定是峰值的条件，a[i] != a[i+1])*/
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		return concreteFind(nums, 0, nums.size() -1);
	}
	int concreteFind(vector<int>& nums, int left, int right)
	{
		if(left == right)
		{
			return left;
		}
		int mid1 = (left + right)/2;
		int mid2 = mid1 + 1;
		if(nums[mid1] > nums[mid2])
		{
			return concreteFind(nums,left,mid1);
		}
		else
		{
			return concreteFind(nums,mid2,right);
		}
	}
};
