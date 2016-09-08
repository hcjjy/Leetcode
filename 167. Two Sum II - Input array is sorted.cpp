/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
方法一：先用target减去一个数字，再利用折半查找另外一个值。
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int n = numbers.size();
		vector<int>subVec(n);
		int i = 0, index = 0;
		for( ; i < n; ++i)
		{
			subVec[i] = target - numbers[i];
			vector<int>::iterator lowIter = lower_bound(numbers.begin(),numbers.end(),subVec[i]);
			index = lowIter -  numbers.begin();
			if(subVec[i] == numbers[index] && i != index)//找到了,记住不能取相同位置的数字
			{
				break;
			}
		}
		if(i > index)
		{
			swap(i,index);
		}
		vector<int>ret(2);
		ret[0] = i + 1;
		ret[1] = index + 1;
		return ret;
	}
};

/*
方法二：直接首位相加一步一步比较，将复杂度减少为O(n)
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int low = 0;
		int high = numbers.size() - 1;
		while(numbers[low] + numbers[high] != target)
		{
			if(numbers[low] + numbers[high] < target)
			{
				low++;
			}
			else
			{
				high--;
			}
		}
		return vector<int>({low+1, high+1});
	}
};
