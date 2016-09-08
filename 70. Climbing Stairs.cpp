/*
https://leetcode.com/problems/climbing-stairs/
方法一：直接法
*/
class Solution {
public:
	int climbStairs(int n) {
	    if(n <= 0)
	    {
	        return 0;
	    }
		vector<int> ret(n + 1);
		ret[0] = 1;
		ret[1] = 1;
		for(int i = 2; i <= n; ++i)
		{
		    ret[i] = ret[i - 1] + ret [i - 2];
		}
		return ret[n];
	}
};
/*
方法二:Using the Fibonacci formular to get the answer directly
This is Fibonacci number, and the world has already worked out an formula that

enter image description here

and where

enter image description here

or you can check the wiki Fibonacci Number

and noticed the Fibonacci begins with F(0)=0, F(1)=1, F(2)=1, F(3)=2

but this problem begins with F'(1)=1, F'(2)=2

So we need a (n++) at the beginning to match the Fibonacci formula
*/
class Solution {
public:
	int climbStairs(int n) {
	    ++n;
	    double root5 = pow(5,0.5);
	    double ret = 1/root5*(pow((1+root5)/2,n) - pow((1-root5)/2,n));
	    return (int)ret;
	}
};
