class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.size()>s.size())
            return "";
        
        map<char,int>ts;
        map<char,int>st;
        int u = 0;
    
        for(auto c:t)
            ts[c]++;
        
        int j = 0;
        int p = -1;
        int l = INT_MAX;
        int i = 0;
        while(i<s.size())
        {
            if(st[s[i]]<ts[s[i]])
                u++;
            st[s[i]]++;
        
            while(u==t.size())
             {
                     if(l>(i-j+1))
                        l = i-j+1,p = j;
                // cout<<s.substr(j,i-j+1)<<" ";
                    st[s[j]]--;
                    if(st[s[j]]<ts[s[j]])
                        u--;
                // cout<<s[j]<<"\n";
                    j++;
                
             }
            ++i;
            // cout<<"\n";
            }
            
        
    if(p==-1)
        return "";
    return s.substr(p,l);
    }
};