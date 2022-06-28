class Solution {
public:
    int minDeletions(string s) {
        
        map<int,int>m;
        map<char,int>u;
        for(auto c:s)
        {
            if(u[c]!=0)
            {
                m[u[c]]--;
                u[c]++;
                m[u[c]]++;
                
            }
            else 
                u[c]++,m[u[c]]++;
        }
        int c=0;
        for(auto it=m.rbegin();it!=m.rend();++it)
        {
            if(m[it->first]>1)
                c+=(it->second-1);
            if(it->first-1!=0 && m[it->first]>1)
            m[it->first-1]+=m[it->first]-1;
        }
    
        return c;
        
    }
};