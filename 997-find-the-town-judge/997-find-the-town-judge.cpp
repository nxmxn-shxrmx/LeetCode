class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1)
            return 1;
        if(trust.size()==0)
            return -1;
        vector<set<int>>v(n+1);
        int x = trust[0][1];
        for(auto c:trust)
        {
            v[c[0]].insert(c[1]);
        }
        int p=0;
        for(int i = 1;i<v.size();++i)
            if(v[i].size()==0)
            {
                p = i;
                v[i].insert(i);
                break;  
            } 
        if(p==0)
        return -1;
        
        for(int i =1;i<v.size();++i)
        {
            if(v[i].find(p)==v[i].end())
                return -1;
        }
        return p;
        
    }
};