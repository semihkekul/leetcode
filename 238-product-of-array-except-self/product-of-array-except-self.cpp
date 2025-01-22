class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        prefix[0] = suffix[nums.size()-1] = 1;

        for(int i = 1; i < nums.size(); ++i)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i = nums.size() - 2; i >= 0; --i)
        {
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            nums[i] = suffix[i] * prefix[i];
        }

        return nums;

    }
};

/*
1, 2, 3, 4
1  1  2  6
24 12  4  1
*/