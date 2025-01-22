class RandomizedSet {
public:
    std::vector<std::pair<int,bool>> NumbersVector;
    std::unordered_set<int> DeletedIndicesSet;
    std::unordered_map<int,int> NumbersMap;

    RandomizedSet() {
        std::srand(std::time(0));
    }
    
    bool insert(int val) {
        auto iter = NumbersMap.find(val);
        if( iter == NumbersMap.end())
        {
            if(!DeletedIndicesSet.empty())
            {
                int index = *DeletedIndicesSet.begin();
                NumbersMap[val] = index;
                DeletedIndicesSet.erase(DeletedIndicesSet.begin());
                NumbersVector[index].first = val;
                NumbersVector[index].second = true;
            }
            else
            {
                NumbersMap[val] = NumbersVector.size();
                NumbersVector.push_back(std::make_pair(val,true));
            }
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto iter = NumbersMap.find(val);
        if(iter != NumbersMap.end())
        {
            std::get<1>(NumbersVector[iter->second]) = false;
            DeletedIndicesSet.insert(NumbersMap[val]);
            NumbersMap.erase(iter);
            return true;
        }
        return false;
    }
    
    void printVector()
    {
        for(auto& p : this->NumbersVector)
        {
            std::cout << p.first << " " << p.second << ", ";
        }
        std::cout << "\n";
    }

    int getRandom() {
        
        int randomIndex;
        
        do
        {
            randomIndex = std::rand() % (NumbersVector.size());
        }
        while(DeletedIndicesSet.find(randomIndex) != DeletedIndicesSet.end());

        return std::get<0>(NumbersVector[randomIndex]);

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */