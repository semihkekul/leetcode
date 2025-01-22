class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i{0};
        int j{1};
        while(i < nums.size())
        {
            if(nums[i] == val)
            {
                while(true)
                {
                    if(j == nums.size())
                    {
                        return i;
                    }

                    if(nums[j] != val)
                    {
                        nums[i] = nums[j];
                        nums[j] = val;
                        break;
                    } 
                    j++;
  
                }
            }
            i++;
            j++;
        }

        return i;
    }
};


/*
2,3,2,3
i j  

*/