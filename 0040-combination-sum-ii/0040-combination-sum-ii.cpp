class Solution {
public:
    set<vector<int>>s;
    void sum(vector<int>&d,vector<int>&c,int i ,int t)
    {
        if(t==0)
        {
            s.insert(d);
            return;
        }
        if(t<0)
            return;
        if(i==c.size())
        return;
        
        d.push_back(c[i]);
        sum(d,c,i+1,t-c[i]);
        d.pop_back();
        while(i+1<c.size() && c[i]==c[i+1])
            ++i;
        sum(d,c,i+1,t);
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<int>d;
        sort(c.begin(),c.end());
        sum(d,c,0,t);
        vector<vector<int>>v(s.begin(),s.end());
        return v;
    }
};