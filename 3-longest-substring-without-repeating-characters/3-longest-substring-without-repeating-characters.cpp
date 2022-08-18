class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        
        int  t = 0;
        map<char,int>m;
        int j = 0;
        for(int i = 0;i<s.size();++i)
        {
            if(m.find(s[i])!=m.end())
                j = max(j,m[s[i]]+1);
            

                m[s[i]]=i;
            
            t = max(t,i-j+1);
            // cout<<t<<" "<<i<<" "<<j<<"\n";
        }
        // cout<<"\n";
        return t;
    }
};