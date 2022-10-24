class Solution {
public:
    int f(int i,vector<string>s,vector<int>&v)
    {
        if(i==s.size())
            return 0;
        
        bool k =0;
        int  l =0;
        unordered_map<char,int>m;
        for(auto c:s[i])
        {
            m[c]++;
            if(m[c]==2)
            {
                k = 1;
                break;
            }
        }
        for(auto c:s[i])
        {
            if(v[c-'a'])
            {
                k =1;
                break;
            }
        
        }
        
        if(!k)
        {
              for(auto c:s[i])
                  v[c-'a']=1;
            l = f(i+1,s,v)+s[i].size();
             for(auto c:s[i])
                  v[c-'a']=0;
        }
        return max(l,f(i+1,s,v));
    }
    int maxLength(vector<string>& arr) {
         vector<int>v(27);
        return f(0,arr,v);
    }
};