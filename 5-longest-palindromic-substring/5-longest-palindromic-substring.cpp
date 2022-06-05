class Solution {
public:
    int u=0,maz=0;
    void pallin(string s,int i,int j)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
            --i,++j;
        
      //  cout<<i+1<<" "<<j-(i+1)<<"\n";
        if(maz<(j-(i+1)))
        {
            u = i+1;
            maz =  j-(i+1);
        }
        
    }
    string longestPalindrome(string s) {
        
        int n = s.size();
        if(n<2)
            return s;
        
        for(int i = 0;i<n-1;++i)
        {
            pallin(s,i,i);//odd
            pallin(s,i,i+1);//even;
        }
        return s.substr(u,maz);
    }
    
};