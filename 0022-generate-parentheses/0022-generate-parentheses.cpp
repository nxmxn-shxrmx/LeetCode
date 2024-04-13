class Solution {
public:
    void recurse(int l,int r,vector<string>&ans,string s)
    {
        if(l==r&&l==0)
        {
            ans.push_back(s);
            return;
        }
        if(l)
            recurse(l-1,r,ans,s+"(");
        if(r>l)recurse(l,r-1,ans,s+")");
    }
    vector<string> generateParenthesis(int n) {
        int l = n;
        int r = n;
        
        vector<string>ans;
        recurse(l,r,ans,"");
        return ans;
    }
};