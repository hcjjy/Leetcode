方法一：用所有数的乘积除以第一个负数之前的数的乘积，和所有数乘积比较选出更大的。再和当前最大的比较。
同时注意边界：1、0的时候重置标志2、只有0和一个负数的情况。
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		int maxPro = nums[0];
		int pre = 1;
		int preNeg = 1;
		bool negative = false;
		bool positive = false;
		for(int i = 0; i < nums.size(); ++i)
		{
			if(nums[i] == 0)//重置
			{
				pre = 1;
				preNeg = 1;
				negative = false;
				maxPro = max(maxPro,0);
			}
			else
			{
				pre *= nums[i];
				if(!negative)
					preNeg = pre;
				if(nums[i] < 0)
					negative = true;
				else
					positive = true;
				if(maxPro > 0 || positive)
					maxPro = max(maxPro,max(pre, pre/preNeg));
				else
					maxPro = max(maxPro,pre);
			}
		}
		return maxPro;
	}
};

方法二：DP的灵活应用
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int maxPro = nums[0];
		int maxPreCur = nums[0];
		int minPreCur = nums[0];
		int maxCur,minCur;
		for (int i = 1; i < nums.size(); ++i)
		{
			maxCur = max(nums[i],max(maxPreCur * nums[i],minPreCur * nums[i]));
			minCur = min(nums[i],min(maxPreCur * nums[i],minPreCur * nums[i]));
			maxPro = max(maxPro, maxCur);
			maxPreCur = maxCur;
			minPreCur = minCur;
		}
		return maxPro;
	}
};

