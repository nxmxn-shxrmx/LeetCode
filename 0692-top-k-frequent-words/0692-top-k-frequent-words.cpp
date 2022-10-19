class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    map<string ,int>m;
    map<int,set<string>>p;
    for(auto c:words)
        m[c]++;        
    
    for(auto c:m)
        p[-c.second].insert(c.first);
    vector<string>v;
    for(auto c:p)
    {
        for(auto x:c.second)
        {
            v.push_back(x);
        if(v.size()==k)
            return v;
        }
    }
        return v;
    }
};