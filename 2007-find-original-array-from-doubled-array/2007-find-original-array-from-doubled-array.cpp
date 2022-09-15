class Solution {
public:
    vector<int> findOriginalArray(vector<int>& v) {
      
        if(v.size()%2)
            return {};
        multiset<int>s(v.begin(),v.end());
        auto it = s.begin();
        vector<int>p;
        while(*it==0 && it!=s.end())
        {
            s.erase(s.find(0));
            if(s.find(0)==s.end())
                return {};
            s.erase(s.find(0));
            // cout<<"f";
            p.push_back(0);
            ++it;
            ++it;
        }
        while(p.size()!=v.size()/2)
        {
            int u = *it;
            if(s.find(2*u)==s.end())
                return {};
            s.erase(s.find(2*u));
            p.push_back(u);
            ++it;
        }
        return p;
        
    }
};