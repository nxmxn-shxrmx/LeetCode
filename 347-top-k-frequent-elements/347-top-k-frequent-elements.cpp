class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
        map<int,int>m;
        for(auto c:nums)
            m[c]++;
        for(auto c:m)
        {
            v.push_back({c.second,c.first});
        }
        sort(v.rbegin(),v.rend());
        vector<int>d;
        for(int i =0;i<k;++i)
            d.push_back(v[i].second);
        return d;
    }
};