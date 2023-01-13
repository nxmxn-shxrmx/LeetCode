class Solution {
public:
    int ans =1;
    int f(int i,vector<vector<int>>&v,string &s)
    {
        int k = 1;
        int p = 0;
        int q = 0;
        for(auto c:v[i])
        {
            int h = f(c,v,s);
            if(s[i]!=s[c])
            {
                if(h>=p)
                {
                    q = p;
                    p = h;
                }
                else if(h>=q)
                    q = h;
            }
        }
        ans = max(ans,k+p+q);
        return k+p;
    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>>v(parent.size());
        for(int  i =1;i<parent.size();++i)
            v[parent[i]].push_back(i);
        
        f(0,v,s);
        return ans;
    }
};