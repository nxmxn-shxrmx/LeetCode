class RandomizedSet {
public:
    unordered_map<int,int>m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(m[val]==1)
            return 0;
        m[val]=1;
        return 1;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end())
            return 0;
        m.erase(val);
        return 1;
    }
    
    int getRandom() {
        int u = rand()%m.size();
        for(auto c:m)
        {
            if(u==0)
                return c.first;
            u--;
        }
        return 1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */