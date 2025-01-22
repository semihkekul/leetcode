class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n - 1)
        {
            if(nums[i] == 0)
            {
                return false;
            }

            int j = i + nums[i];
            int mxNextJump = 0;
            int mxNextJumpIdx = j;
            if(j >= n-1)
            {
                return true;
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

            i = mxNextJumpIdx;
        }
        return true;
    }
};

/*

1,1,2,2,0,1,1
  i j
jR = 1


*/