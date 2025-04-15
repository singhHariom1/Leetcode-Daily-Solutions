// 🔨 Brute Force (O(n²)):

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                profit = max(profit, prices[j] - prices[i]);
            }
        }
        return profit;
    }
};

// ⚡ Optimal (O(n) time, O(1) space):

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = INT_MAX;
        int profit = 0;
        for (int price : prices)
        {
            min_price = min(min_price, price);
            profit = max(profit, price - min_price);
        }
        return profit;
    }
};