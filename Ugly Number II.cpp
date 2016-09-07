/*
https://leetcode.com/problems/ugly-number-ii/
方法一：直接将所有的ugly求出来,每次查找的时候直接读取即可
*/
class Solution {
public:
	vector<int>uglyVec;
	void initVec()//限制自己在不使用long long的情况下判断
	{
		for(int i = 1;i < INT_MAX; )
		{
			for(int j = 1; j <= INT_MAX / i; )
			{
				for(int k = 1; i*j <= INT_MAX / k; )
				{
					uglyVec.push_back(i*j*k);
					if(k > INT_MAX / 5)
					{
						break;
					}
					else
					{
						k = k * 5;
					}
				}
				if (j > INT_MAX / 3)
				{
					break;
				}
				else
				{
					j = j * 3;
				}
			}
			if(i > INT_MAX / 2)
			{
				break;
			}
			else
			{
				i *= 2;
			}
		}
		sort(uglyVec.begin(),uglyVec.end());
	}
	int nthUglyNumber(int n) {
	    if(!uglyVec.size())
		{
		    initVec();
		}
		if(n <= 0)//可以不需要，只是为了健壮性
		{
			return 0;
		}
		if(n <= uglyVec.size())
		{
			return uglyVec[n - 1];
		}
		return uglyVec.back();
	}
};

/*
方法二：利用DP解决
We have an array k of first n ugly number. We only know, at the beginning, the first one, which is 1. Then

k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1. Then we test:

k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases such as 6, in which we need to forward both pointers of 2 and 3.
*/

class Solution {
public:
	int nthUglyNumber(int n) {
	  	if(n <= 0)//可以不需要，只是为了健壮性
		{
			return 0;
		}
		vector<int> uglyVec(n,0);
		uglyVec[0] = 1;
		int t0 = 0, t1 = 0, t2 = 0;
		for(int i = 1; i < n; ++i)
		{
		    int twoMin = min(2 * uglyVec[t0], 3 * uglyVec[t1]);
		    uglyVec[i] = min(twoMin, 5 * uglyVec[t2]);
		    if(uglyVec[i] == 2 * uglyVec[t0])
		    {
		        ++t0;
		    }
		    if(uglyVec[i] == 3 * uglyVec[t1])
		    {
		        ++t1;
		    }
		    if(uglyVec[i] == 5 * uglyVec[t2])
		    {
		        ++t2;
		    }
		}
		return uglyVec.back();
	}
};
