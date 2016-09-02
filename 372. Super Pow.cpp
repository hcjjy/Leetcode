/*
https://leetcode.com/problems/super-pow/
思路：1.找出余数的周期T，并且保存各个余数。
2.因为指数很大很大，所以必须模拟除法（b/T）求出b在周期的位置，然后得到该位置所对应的余数。
边界:考虑到ret == 0的情况防止下标为负数。
*/

class Solution{
public:
    int superPow(int a, vector<int>& b) {
		int div = 1337;
        int T = 1;
		bool flag = false;
		int cpyA = a;
		vector<int>mod;
		mod.push_back(cpyA % div);
		//找到周期
		while(!flag)
		{
			int cpyA = ((cpyA%div) * (a%div))%div;//注意溢出,为了防止溢出将余数赋给cpyA
			if(cpyA == mod[0])
			{
				flag = true;
			}
			else
			{
				mod.push_back(cpyA);
				++T;
			}
		}
		//模拟除法
		int ret = 0;
		int n = b.size();
		for(int i = 0; i < n;)
		{
			do
			{
				ret = ret*10 + b[i++];
			}while(i < n && ret < div);
			ret %= T;
		}
		if(ret == 0)
		{
			++ret;
		}
		return mod[ret - 1];
    }	
};

/*
方法二:
One knowledge: ab % k = (a%k)(b%k)%k
Since the power here is an array, we'd better handle it digit by digit.
One observation:
a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
Looks complicated? Let me put it other way:
Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;
Implementation of this idea:
*/
class Solution{
public:
	const int base = 1337;
    int powmod(int a, int k)//a^k mod 1337 where 0 <= k <= 10
	{
		a %= base;
		int ret = 1;
		for(int i = 0; i < k; ++i)
		{
			ret = ret * a % base;//because of a =% base,so a < base,in addition base*base < MAX_INT,so can directly ab%k
		}
		return ret;
	}
	int superPow(int a, vector<int>& b){
		if(b.size() == 0)
		{
			return 1;
		}
		int last_digit = b.back();
		b.pop_back();
		return powmod(superPow(a,b),10) * powmod(a,last_digit) % base;
	}
};
