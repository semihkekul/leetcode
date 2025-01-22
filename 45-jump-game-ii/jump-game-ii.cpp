class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int noOfJumps = 1;
        int n = nums.size();
        int i = 0;
        while(i < n - 1)
        {
            int j = i + nums[i];
            int mxNextJump = 0;
            int mxNextJumpIdx = j;
            if(j >= n-1)
            {
                return noOfJumps;
            }
            while(j > 0)
            {
                if(nums[j] + j > mxNextJump)
                {
                    mxNextJump = nums[j] + j;
                    mxNextJumpIdx = j;
                }
                --j;
            }
            noOfJumps++;
            i = mxNextJumpIdx;
        }
        return noOfJumps;   
    }
};