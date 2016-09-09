/*
https://leetcode.com/submissions/detail/73608811/
居然是2和3之间折腾，真是一个魔法数字啊。
不过有人通过数学求导跟e扯上了关系，我想是有道理的，虽然没有仔细阅读。
*/
class Solution {
public:
	int integerBreak(int n) {
	    if(n <= 3)
	    {
	        return n-1;
	    }
		if( n % 3 == 0)
		{
			return pow(3*1.0,n/3);
		}
		else if( n % 3 == 1)
		{
			return pow(3*1.0,(n - 4)/3)*4;
		}
		else
		{
			return pow(3*1.0,(n - 2)/3)*2;

		}
	}
};
