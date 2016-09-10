/*
https://leetcode.com/problems/sqrtx/
二分法
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
        {
            return 0;
        }
        int left = 1, right = INT_MAX;
        while(left < right)
        {
            int mid = left + (right - left)/2; //(right + left)/2可能会溢出故换成left + (right - left)/2
            if(mid > x / mid)
            {
                right = mid - 1;
            }
            else
            {
                if(mid+1 > x / (mid + 1))
                {
                    return mid;
                }
                left = mid + 1;
            }
        }
        return left;
    }
};
