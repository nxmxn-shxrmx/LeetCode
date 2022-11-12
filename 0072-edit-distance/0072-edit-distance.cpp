class Solution {
public:
    vector<vector<int>>v;
    int f(string s,string t,int i,int j)
    {
        if(i==s.size() && j==t.size())
            return 0;
        
        if(i==s.size())
            return t.size()-j;
        if(j==t.size())
            return s.size()-i;
        if(v[i][j]!=-1)
            return v[i][j];
        int k  = f(s,t,i+1,j+1);
        if(s[i]!=t[j])
            k+=1;
        k = min(f(s,t,i+1,j)+1,k);
        k = min(f(s,t,i,j+1)+1,k);
        return v[i][j]=k;
    }
    int minDistance(string s, string t) {
        v = vector<vector<int>>(s.size()+1,vector<int>(t.size()+1,0));
        for(int i = 0;i<=t.size();++i)
            v[s.size()][i]=t.size()-i;
        for(int i = 0;i<=s.size();++i)
            v[i][t.size()]=s.size()-i;
        
        for(int i = s.size()-1;~i;--i)
        {
            for(int j = t.size()-1;~j;--j)
            {
                int k = v[i+1][j+1];
                if(s[i]!=t[j])
                    k+=1;
                k =  min(v[i+1][j]+1,k);
                k = min(v[i][j+1]+1,k);
                v[i][j]=k;
            }
        }
        return v[0][0];
    }
};