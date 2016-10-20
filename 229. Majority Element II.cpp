/*
此种题目就是采用抵消的方式，能解决一系列关于出现次数超过(n/i)的问题，每i个不同的数字想抵消，排除的数字一定不可能出现次数超过(n/i)，
剩下的数字可能是次数超过(n/i)。
*/
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int ret1 = -1, ret2 = 0, cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == ret1)
				++cnt1;
			else if (nums[i] == ret2)
				++cnt2;
			else if (cnt1 == 0)
				ret1 = nums[i], ++cnt1;
			else if (cnt2 == 0)
				ret2 = nums[i], ++cnt2;
			else
				--cnt1, --cnt2;
		}
		cnt1 = cnt2 = 0;
		//剩下的数字只是可能超过n/3，故还需遍历
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == ret1)
				++cnt1;
			else if (nums[i] == ret2)
				++cnt2;
		}
		vector<int> rets_;
		if (cnt1 > nums.size() / 3)
			rets_.push_back(ret1);
		if(cnt2 > nums.size() / 3)
			rets_.push_back(ret2);
		return rets_;
	}
};
