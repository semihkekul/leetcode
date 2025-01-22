class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i{0};
        int j{0};

        while(j < nums.size())
        {
            if(nums[i] == nums[j])
            {
                j++;
                continue;
            }
            else
            {
                nums[i+1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }
};

/*
1,1,2
i
    j   
*/