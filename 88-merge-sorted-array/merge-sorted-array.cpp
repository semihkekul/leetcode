class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> Merged;
        int i1{0};
        int i2{0};
        while(i1 < m && i2 < n)
        {
            int v1{nums1[i1]};
            int v2{nums2[i2]};

            if(v1 > v2)
            {
                Merged.push_back(v2);
                i2++;
            }
            else
            {
                Merged.push_back(v1);    
                i1++;
            }
        }

        if(i1 < m)
        {
            std::copy(nums1.begin() + i1 , nums1.begin() + m, std::back_inserter(Merged));
        }

        if(i2 < n)
        {
            std::copy(nums2.begin() + i2 , nums2.begin() + n, std::back_inserter(Merged));
        }

        nums1.clear();

        nums1 = Merged;

        //std::copy(Merged.begin(), Merged.end() + n, std::back_inserter(nums1));

    }
};