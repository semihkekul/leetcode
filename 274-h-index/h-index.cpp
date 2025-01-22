class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> counts(citations.size());

        for(int c  : citations)
        {
            if(c > citations.size())
            {
                counts[citations.size()-1]++;
            }
            else if(c != 0)
            {
                counts[c-1]++;
            }
        }
        
        for(int i = counts.size()-1; i >= 0; --i)
        {
            if(i < counts.size()-1)
            {
                counts[i] += counts[i+1];
            }
            if(counts[i] >= i+1) return i+1;
        }

        return 0;

    }
};

/*
0 0 0 0 0
1 2 3 4 5  
*/