// ✅ Brute Force Approach:

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size(), index = 0;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                arr[index++] = nums[i];
            }
        }
        nums = arr;
    }
};

// ✅ Optimal Approach

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0, right = 0, n = nums.size();
        while (right < n)
        {
            if (nums[left] == 0 && nums[right] != 0)
            {
                swap(nums[left++], nums[right]);
            }
            else if (nums[left] != 0)
            {
                left++;
            }
            right++;
        }
    }
};

// Best Written Code

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] != 0)
            {
                swap(nums[left++], nums[right]);
            }
        }
    }
};