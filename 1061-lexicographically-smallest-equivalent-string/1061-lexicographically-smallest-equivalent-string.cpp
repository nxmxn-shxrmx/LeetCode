class Solution {
public:
    int find(vector<int>&v,int c)
    {
        if(c==v[c])
            return c;
        return v[c] = find(v,v[c]);
    }
    string smallestEquivalentString(string s1, string s2, string b) {
        vector<int>v(26,-1);
        for(int i = 0;i<s1.size();++i)
        {
            if(v[s1[i]-'a']==-1)
                v[s1[i]-'a']=s1[i]-'a';
            
            if(v[s2[i]-'a']==-1)
                v[s2[i]-'a']=s2[i]-'a';
            
            int u = find(v,s1[i]-'a');
            int p = find(v,s2[i]-'a');
            
            if(u>p)
                swap(u,p);
            
            v[p]=u;
            
        }
        for(int i = 0;i<b.size();++i)
            if(v[b[i]-'a']!=-1)
            b[i] = char(find(v,b[i]-'a')+97);
        
        
        return b;
    }
};