class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        int mn{INT_MAX};

        for(int p : prices)
        {
            if(p > mn)
            {
                totalProfit += p - mn;
                mn = p;
            }
            else
            {
                mn = p;
            }
        }

        return totalProfit;

    }
};