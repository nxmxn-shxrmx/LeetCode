class Solution {
public:
    vector<string>v;

    void reus(int i,int l,int r,string s,int n)
    {
        if(i==2*n)
        {
            v.push_back(s);
            return;
        }
        if(l<n)
            reus(i+1,l+1,r,s+"(",n);
        if(r<l && r<n)
            reus(i+1,l,r+1,s+")",n);

    }
    vector<string> generateParenthesis(int n) {
        reus(0,0,0,"",n);
        return v;
    }
};