/*
https://leetcode.com/problems/zigzag-conversion/
n=numRows
Δ=2n-2    1                           2n-1                         4n-3
Δ=        2                     2n-2  2n                    4n-4   4n-2
Δ=        3               2n-3        2n+1              4n-5       .
Δ=        .           .               .               .            .
Δ=        .       n+2                 .           3n               .
Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
Δ=2n-2    n                           3n-2                         5n-4
*/
class Solution {
public:
	string convert(string s, int numRows) {
		if(numRows == 1)
		{
			return s;
		}
		string ret;
		for(int i = 0; i < numRows; ++i)
		{
			int oneStep = 2 * (numRows - i - 1);
			int twoStep = 2 * i;
			bool flag = false;
			for(int j = i; j < s.length();)
			{
				if(!flag)
				{
					if(oneStep != 0)
					{
						ret += s[j];
						j += oneStep;
					}
					
				}
				else
				{
					if(twoStep != 0)
					{
						ret += s[j];
						j += twoStep;
					}
				}
				flag = !flag;
			}
		}
		return ret;
	}
};
