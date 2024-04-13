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
        if(t<0||i==c.size())
            return;
        
        
            d.push_back(c[i]);
            sum(t-c[i],d,c,i);
            d.pop_back();
            sum(t,d,c,1+i);
        
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int>d;
        sum(t,d,c,0);
        vector<vector<int>>v(s.begin(),s.end());
        return v;
    }
};