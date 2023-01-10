class Solution {
public:
    int mz = 0;
    int u = 0;
    void chek(string s,int i,int j)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
            --i,j++;
        j--;
        ++i;
        if(mz<(j-i+1))
        {
            mz=(j-i+1);
            u = i;
        }
    }
    string longestPalindrome(string s) {
        
        for(int i = 0;i<s.size();++i)
        {
            chek(s,i,i);
            chek(s,i,i+1);
        }
        return s.substr(u,mz);
        
    }
};