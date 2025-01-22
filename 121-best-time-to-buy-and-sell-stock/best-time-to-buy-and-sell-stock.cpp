class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn{INT_MAX};
        int profit = 0;
        for(int p : prices)
        {
            if(p < mn)
            {
                mn = p;
            }
            else
            {
                profit = std::max(profit, p - mn);
            }
        }

        return profit;
    }
};


/*
mn = 1
mx = 4
7,1,5,3,6,4
    i 

*/