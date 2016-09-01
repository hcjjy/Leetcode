/*
https://leetcode.com/problems/power-of-two/
边界：n为负数
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n <= 0)
        {
            return false;
        }
        while(n > 1)
        {
            if( n % 2 != 0)
            {
                return false;
            }
            else
            {
                n = n / 2;
            }
        }
        return true;
    }
};

/*
Power of 2 means only one bit of n is '1', so use the trick n&(n-1)==0 to judge whether that is the case
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n - 1));
    }
};
