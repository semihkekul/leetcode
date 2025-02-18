class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);

        for(int i = 0; i < ratings.size() - 1; ++i)
        {
            if(ratings[i+1] > ratings[i] && candies[i+1] <= candies[i] )
            {
                candies[i+1] = candies[i] + 1;
            }
        }

        for(int i = ratings.size() - 1; i > 0; --i)
        {
            if(ratings[i-1] > ratings[i] && candies[i-1] <= candies[i] )
            {
                candies[i-1] = std::max(candies[i] + 1, candies[i-1]);
            }
        }

        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};

/*
1 2 3 2 1
1 2 3 1 
*/