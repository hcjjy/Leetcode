/*
https://leetcode.com/problems/missing-number/
边界：数字可能是乱序的
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int n = nums.size();
		bool visited[n + 1];
		memset(visited,0,sizeof(bool) * (n + 1));
		for(int i = 0; i < n; ++i)
		{
			visited[nums[i]] = true;
		}
		for(int i = 0; i < n; ++i)
		{
			if(!visited[i])
				return i;
		}
		return n;
    }
};

/*
方法二：
0...n之和减去vector<int>nums各个数字之和即可求出遗失的数据。
边界:为了防止溢出所以不先求和
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int ret = n;
		for(int i = 0; i < n; ++i)
		{
			ret -= nums[i];
			ret += i;
			/*
			上两个语句可被下面两语句替换，按位运算,执行速度击败90%以上的人哦。
			ret ^= nums[i];
			ret ^= nums[i];
			*/
		}
		return ret;
	}
};