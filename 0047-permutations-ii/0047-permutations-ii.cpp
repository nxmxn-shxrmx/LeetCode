class Solution {
public:
    set<vector<int>>s;
    void perm(vector<int>&d,map<int,int>&m,int i,int t)
    {
        if(i==t)
        {
            s.insert(d);
            return;
        }
        for(auto c:m)
        {
            if(c.second>0)
            {
                d.push_back(c.first);
                m[c.first]--;
                perm(d,m,i+1,t);
                d.pop_back();
                m[c.first]++;
            }
        }
        

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int>m;
        int t = 0;
        for(auto c:nums)
            m[c]++,t++;
        vector<int>d;
        perm(d,m,0,t);
        vector<vector<int>>v(s.begin(),s.end());
        return v;       
    }
};