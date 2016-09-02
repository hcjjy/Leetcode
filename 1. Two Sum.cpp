//https://leetcode.com/problems/two-sum/
/*思路：直接法，时间复杂度为n^2*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size(),i,j;
		for(i = 0; i < n; ++i)
		{
			for(j = i + 1; j < n; ++j)
			{
				if(a[i] + a[j] == target)
				{
					break;
				}
			}
			if(j < n)
			{
				break;
			}
		}
		vector<int> vecIdx{i,j};
		return vecIdx;
	}
};
/*
思路：先用时间复杂度为nlogn的排序算法将容器排序，然后再用折半查法查找这两个数字，
最后在排序之前拷贝的一份容器中查找这两个数字的下标。这样时间复杂度就能控制在nlogn。
注意一点：所选排序算法必须是稳定排序，否则在遇到相同值时下标会紊乱。
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int b[right - left + 1];
		int i = left, j = mid + 1, k = 0;
		while(i <= mid && j <= right)
		{
			if(a[i] <= a[j])
			{
				b[k++] = a[i++];
			}
			else
			{
				b[k++] = a[j++];
			}	
		}
		while(i <= mid)
		{
			b[k++] = a[i++];
		}
		while(j <= right)
		{
			b[k++] = a[j++];
		}
		for(int i = 0; i < k; ++i)
		{
			a[left + i] = b[i];
		}
	}
	void mergeSort(vector<int>& a,int left, int right)
	{
		if(left < right)
		{
			int mid = (left + right)/2;
			mergeSort(a, left, mid);
			mergeSort(a, mid + 1, right);
			insertSort(a, left, mid, right);
		}
	}
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> copynums(nums);
		int n = nums.size();
		//std::sort(nums.begin(), nums.end());
		mergeSort(nums, 0, n - 1);
		int one, other;
		for(int i = 0;i < n; ++i)
		{
			other= target - nums[i];
			int mid = (i+ 1 + n - 1)/2;
			int low = i + 1;
			int high = n - 1;
			while(low <= high)
			{
				if(nums[mid] == other)
				{
					one = nums[i];
					break;
				}
				if(nums[mid] > other)
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
				mid = (low + high)/2;
			}
			if(low <= high)
			{
				break;
			}
		}
		int idx1 = 0,idx2 = 1;
		bool flag1 = false,flag2 = false;
		for(int i = 0; i < n; ++i)
		{
			if(flag1 && flag2)
			{
				break;
			}
			if(one == copynums[i] && !flag1)
			{
				idx1 = i;
				flag1 = true;
			}
			else if(other == copynums[i] && !flag2)
			{
				idx2 = i;
				flag2 = true;
			}
		}
		vector<int>vecIdx{idx1,idx2};
		return vecIdx;
    }
};