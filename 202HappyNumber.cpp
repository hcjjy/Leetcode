/*
https://leetcode.com/problems/happy-number/
思路：
用map<int,int>保存每次平方和计算结果，一直计算下去，直到出现以下情况：
1.计算结果与map保存的数据重复，计算结束，不是happy Number。
2.计算结果为1，计算结束，是happy Number。
*/
//方法一：
class Solution {
public:
    bool isHappy(int n) {
        map<int,int>sumMap;
		//各个位平方和计算
		int sum = n;
		bool flag = true;
		while(flag)
		{
			if(sum == 1)
			{
				return true;
			}
			if(sumMap.count(sum))
			{
				return false;
			}
			sumMap[sum] = 1;
			n = sum;
			sum = 0;
			int tmpN = n;
			do 
			{
				int i = tmpN % 10;
				sum += i*i;
				tmpN = tmpN/10;
			}while(tmpN);

		}
		return true;
    }
};

//方法二:巧妙的利用Floyd判圈算法(龟兔赛跑算法)--龟走一步，兔走两步

class Solution {
public:
	int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}
}





