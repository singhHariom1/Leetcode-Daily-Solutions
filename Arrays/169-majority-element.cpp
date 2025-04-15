// ✅ Brute Force Approach:

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == nums[i])
                    count++;
            }
            if (count > n / 2)
                return nums[i];
        }
        return -1; // In case majority element doesn't exist
    }
};

// ✅ Better Approach (Using Hash Map / Unordered Map):

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int num : nums)
        {
            freq[num]++;
            if (freq[num] > n / 2)
                return num; // Early exit if majority found
        }

        return -1; // No majority element (edge case)
    }
};

// ✅ Optimal Approach (Moore’s Voting Algorithm):

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, candidate = -1;

        // Phase 1: Find candidate
        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
                count = 1;
            }
            else
            {
                count += (num == candidate) ? 1 : -1;
            }
        }

        // Phase 2: Verify candidate
        count = 0;
        for (int num : nums)
        {
            if (num == candidate)
                count++;
        }

        return (count > nums.size() / 2) ? candidate : -1;
    }
};
