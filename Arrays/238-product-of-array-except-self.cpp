// ❌ Using division (fails for the case where the array contains 0):

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int product = 1;
        for (int num : nums)
        {
            product *= num;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = product / nums[i];
        }
        return ans;
    }
};

// 🧱  Approach 1: Brute Force Approach:

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            int product = 1;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    product *= nums[j];
                }
            }
            result[i] = product;
        }
        return result;
    }
};

// ✅ Approach 2: Using prefix and suffix arrays:

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        vector<int> prefixArray(n);
        vector<int> suffixArray(n);
        for (int i = 0; i < n; i++)
        {
            prefixArray[i] = prefix;
            prefix *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            suffixArray[i] = suffix;
            suffix *= nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = prefixArray[i] * suffixArray[i];
        }
        return ans;
    }
};

// ✅ Approach 3: Optimal Approach (Space-Optimized Prefix & Suffix in One Pass Each):

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);
        int prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] = prefix;
            prefix *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};