class Solution {
public:
    vector<int>ans;
    vector<int>f(int &i,int &pre,vector<vector<int>>&v,string &l)
    {
        vector<int>u(26);
        for(auto c:v[i])
        {
            if(c==pre)
                continue;
            
            vector<int>p=f(c,i,v,l);
            for(int i = 0;i<p.size();++i)
                u[i]+=p[i];
            
        }
        u[l[i]-'a']++;
        ans[i] = u[l[i]-'a'];
        return u;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>v(n);
        ans = vector<int>(n);
        for(auto c:edges)
        {
            v[c[0]].push_back(c[1]);
            v[c[1]].push_back(c[0]);
        }
        int i = 0;
        int pre =-1;
        f(i,pre,v,labels);
        return ans;
    }
};