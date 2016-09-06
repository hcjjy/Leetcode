/*
https://leetcode.com/problems/add-digits/
时间复杂度为O(1)的方法思路：13 = 1 + 3,其实是10 变成了1,其中(10 - 1)%9 == 0,
23 = 2 + 3,其实是20变成了2其中(20 - 2)%9 == 0可以总结为模9的想法。
*/
class Solution {
public:
    int addDigits(int num) {
        /*int ret = num;
        while(ret >= 10)
        {
            int tmp = 0;
            do
            {
                tmp += ret%10;
                ret /= 10;
            }while(ret > 0);
            ret = tmp;
        }
        return ret;*/
        return (num-1) % 9 + 1;
    }
};
