class Solution {
public:
    map<int,int>m;
    map<int,long long>s;
    int find(int v)
    {
        if(m[v]==v)
            return v;
        
        return m[v]=find(m[v]);
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& ed) {

        vector<int>v;
        for(auto c:ed)
        {
            if(m[c[0]]==0 && m[c[1]]==0)
            {
                  m[c[1]]=c[1];
                  m[c[0]]=c[1];
                  s[c[1]]=2;
            }
            else if(m[c[1]]==0)
            {
                int u =find(c[0]);
                m[c[1]]=u;
                s[u]++;
            }
            else if(m[c[0]]==0)
            {
                int u = find(c[1]);
                m[c[0]]=u;
                s[u]++;
            }
            else
            {
                int a = find(c[0]);
                int b = find(c[1]);
                if(a!=b)
                {
                    if(s[a]<s[b])
                        swap(a,b);
                    
                    m[b]=a;
                    s[a]+=s[b];
                    continue;
                }
                
                v.clear();
                v.push_back(c[0]);
                v.push_back(c[1]);
            }
        }
        return v;
    }
};