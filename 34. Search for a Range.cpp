//解法一
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int start = -1, end = -1;
		int low = 0, high = nums.size() - 1;
		int mid = (low + high)/2;
		while(low <= high)
		{
			if(nums[mid] == target)
				break;
			else if(nums[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
			mid = (low + high) / 2;
		}
		if (low <= high)
		{
			start = end = mid;
			//left
			int cpy_mid =  mid;
			int cpy_high = high;
			high = mid - 1;
			mid = (low + high) / 2;
			while(low <= high)
			{
				if(nums[mid] == target)
				{
					start = mid;
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
				mid = (low + high) / 2;
			}
			//right
			mid =  cpy_mid;
			high = cpy_high;
			low = mid + 1;
			mid = (low + high) / 2;
			while(low <= high)
			{
				if(nums[mid] == target)
				{
					end = mid;
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
				mid = (low + high) / 2;
			}
		}
		vector<int> ret(2);
		ret[0] = start;
		ret[1] = end;
		return ret;
	}
	
};
/*
The problem can be simply broken down as two binary searches for the begining and end of the range, respectively:

First let's find the left boundary of the range. We initialize the range to [i=0, j=n-1]. In each step, calculate the middle element [mid = (i+j)/2]. Now according to the relative value of A[mid] to target, there are three possibilities:

If A[mid] < target, then the range must begins on the right of mid (hence i = mid+1 for the next iteration)
If A[mid] > target, it means the range must begins on the left of mid (j = mid-1)
If A[mid] = target, then the range must begins on the left of or at mid (j= mid)
Since we would move the search range to the same side for case 2 and 3, we might as well merge them as one single case so that less code is needed:

2*. If A[mid] >= target, j = mid;

Surprisingly, 1 and 2* are the only logic you need to put in loop while (i < j). When the while loop terminates, the value of i/j is where the start of the range is. Why?

No matter what the sequence originally is, as we narrow down the search range, eventually we will be at a situation where there are only two elements in the search range. Suppose our target is 5, then we have only 7 possible cases:

case 1: [5 7] (A[i] = target < A[j])
case 2: [5 3] (A[i] = target > A[j])
case 3: [5 5] (A[i] = target = A[j])
case 4: [3 5] (A[j] = target > A[i])
case 5: [3 7] (A[i] < target < A[j])
case 6: [3 4] (A[i] < A[j] < target)
case 7: [6 7] (target < A[i] < A[j])
For case 1, 2 and 3, if we follow the above rule, since mid = i => A[mid] = target in these cases, then we would set j = mid. Now the loop terminates and i and j both point to the first 5.

For case 4, since A[mid] < target, then set i = mid+1. The loop terminates and both i and j point to 5.

For all other cases, by the time the loop terminates, A[i] is not equal to 5. So we can easily know 5 is not in the sequence if the comparison fails.

In conclusion, when the loop terminates, if A[i]==target, then i is the left boundary of the range; otherwise, just return -1;

For the right of the range, we can use a similar idea. Again we can come up with several rules:

If A[mid] > target, then the range must begins on the left of mid (j = mid-1)
If A[mid] < target, then the range must begins on the right of mid (hence i = mid+1 for the next iteration)
If A[mid] = target, then the range must begins on the right of or at mid (i= mid)
Again, we can merge condition 2 and 3 into:

2* If A[mid] <= target, then i = mid;
However, the terminate condition on longer works this time. Consider the following case:

[5 7], target = 5
Now A[mid] = 5, then according to rule 2, we set i = mid. This practically does nothing because i is already equal to mid. As a result, the search range is not moved at all!

The solution is by using a small trick: instead of calculating mid as mid = (i+j)/2, we now do:

mid = (i+j+1)/2
Why does this trick work? When we use mid = (i+j)/2, the mid is rounded to the lowest integer. In other words, mid is always biased towards the left. This means we could have i == mid when j - i == mid, but we NEVER have j == mid. So in order to keep the search range moving, you must make sure the new i is set to something different than mid, otherwise we are at the risk that i gets stuck. But for the new j, it is okay if we set it to mid, since it was not equal to mid anyways. Our two rules in search of the left boundary happen to satisfy these requirements, so it works perfectly in that situation. Similarly, when we search for the right boundary, we must make sure i won't get stuck when we set the new i to i = mid. The easiest way to achieve this is by making mid biased to the right, i.e. mid = (i+j+1)/2.
*/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret(2,-1);
		int low = 0, high = nums.size() - 1;
		while(low < high)
		{
			int mid = (low + high)/2; //向下取整
			if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid;
		}
		if(nums[low] != target)
			return ret;
		ret[0] = low;
		high = nums.size() - 1;
		while(low < high)
		{
			int mid = (low + high + 1)/2; //向上取整
			if(nums[mid] > target)
				high = mid - 1;
			else
				low = mid;
		}
		ret[1] = high;
		return ret;
	}
};
