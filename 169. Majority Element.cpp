/*
https://leetcode.com/problems/majority-element/
方法一：先排序，在计算出现的次数的数字复杂度为O(n*lgn)
*/
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int cmp = nums[0];
		int times = 1;
		for(int i = 1; i < nums.size(); ++i)
		{
			if(nums[i] != cmp)
			{
				cmp = nums[i];
				times = 1;
			}
			else
			{
				times++;
				if(times > nums.size()/2)
				{
					break;
				}
			}
		}
		return cmp;
	}
};

/*
方法二：因为次数对多的数字出现超过了一半，所以最坏的情况下，每次都和其他数字抵消最后也还能剩下没有被抵消的该数字。(genius algorithm)
*/
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int ret = nums[0];
		int cnt = 1;
		for(int i = 1; i < nums.size(); ++i)
		{
			if(cnt == 0)
			{
				ret = nums[i];
				cnt = 1;
			}
			else if(ret == nums[i])
			{
				++cnt;
			}
			else
			{
				--cnt;
			}
		}
		return ret;
	}
};
