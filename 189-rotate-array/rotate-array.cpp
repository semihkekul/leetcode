class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> extraSpace = nums;
        int s = extraSpace.size();
        for(int i = 0; i < extraSpace.size(); ++i)
        {
            int j{ (i + k) % s};
            nums[j] = extraSpace[i];
        }

    }
};



