class Solution {
public:
    set<vector<int>>s;
    void sum(int t,vector<int>&d,vector<int>&c,int i)
    {
        if(t==0)
        {
            s.insert(d);
            return;
        }
        if(t<0)
            return;
        
        for(int j = i;j<c.size();++j)
        {
            d.push_back(c[j]);
            sum(t-c[j],d,c,j);
            d.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int>d;
        sum(t,d,c,0);
        vector<vector<int>>v(s.begin(),s.end());
        return v;
    }
};