/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
思路：先找到拐点，在进行查找最大利润
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
		{
			return 0;
		}
		int i = 1;
		while(i < prices.size()&& prices[i-1] >= prices[i])
		{
			++i;
		}
		if (i == prices.size())
		{
			return 0;
		}
		int buy = prices[i-1];
		int profit = 0;
		for ( ; i < prices.size(); ++i)
		{
			if(prices[i] - buy > profit)
			{
				profit = prices[i] - buy;
			}
			else if (prices[i] < buy)
			{
				buy = prices[i];
			}
		}
		return profit;
	}
};
/*
简单的DP问题
思路：更新最小的买入价格，更新最大利润。
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int minbuy = INT_MAX;
		int maxprofit = 0;
		for(int i = 0; i < prices.size(); ++i)
		{
			minbuy = min(minbuy, prices[i]);
			maxprofit = max(maxprofit, prices[i] - minbuy);
		}
		return maxprofit;
	}
};
