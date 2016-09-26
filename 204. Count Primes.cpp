/*
https://leetcode.com/problems/count-primes/
方法一：模拟法
*/
class Solution {
public:
	int countPrimes(int n) {
		if(n <= 2)
			return 0;
		int ret = 1;
		for (int i = 3; i < n; i += 2)
		{
		    int j = 3;
			for( ;j <= i/j; j+= 2)
			{
				if (i % j == 0)
				{
					break;
				}
			}
			if(j > i/j)
				++ret;
		}
		return ret;
	}
};
/*
方法二：埃拉筛选法
排除2,3,4,5...i(i*i < n)的1,2,3,4,5,6....j(i*j < n)倍数剩下的即为素数
*/
class Solution {
public:
	int countPrimes(int n) {
		if(n <= 2)
			return 0;
		vector<bool> ret(n, false);
		for (int i = 2; i <= (n-1)/i; ++i)
		{
			if(!ret[i])
			{
				for (int j = i*i; j < n; j += i)
				{
					ret[j] = true;
				}
			}
		}
		int num = 0;
		for(int i = 2; i < n; ++i)
		{
			if(!ret[i])
				++num;
		}
		return num;
	}
};
/*
方法三：欧拉筛选法
每一个合数都用最小的素因子排除，故时间复杂度为O(n)。其实欧拉筛选法是埃拉筛选法的优化版，因为埃拉筛选法可能会出现重复合数排除的可能。
*/
class Solution {
public:
	int countPrimes(int n){
		int *ret = new int[n];
		int num = 0;
		bool *notPrime = new bool[n];
		memset(notPrime, 0, sizeof(bool) * n);
		for(int i = 2; i < n; ++i)
		{
			if (!notPrime[i])
			{
				ret[num++] = i;
			}
			for (int j = 0; j < num && ret[j] * i < n; ++j)
			{
				notPrime[ret[j] * i] = true;
				if (i % ret[j] == 0)
				{
					break;
				}
			}
		}
		delete[] ret;
		delete[] notPrime;
		return num;
	}
};

