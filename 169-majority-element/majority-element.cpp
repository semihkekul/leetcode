class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> Items;

        for(int n: nums)
        {
            Items[n]++;
            if(Items[n] > (nums.size() / 2)) return n;
        }
        return 0;
    }
};