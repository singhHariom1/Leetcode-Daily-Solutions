// ✅ Greedy Approach (O(n) time, O(1) space):

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int buy_price = INT_MAX;
        for (int price : prices)
        {
            buy_price = min(buy_price, price);
            if (price > buy_price)
            {
                profit += price - buy_price;
                buy_price = price;
            }
        }
        return profit;
    }
};

// ⚡ Greedy Approach with Better Code (O(n) time, O(1) space):

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};