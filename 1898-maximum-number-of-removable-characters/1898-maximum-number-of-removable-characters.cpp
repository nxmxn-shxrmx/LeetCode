class Solution {
public:
    bool check(int k,string s,string p,map<int,int>&v)
    {
        int u = 0;
        for(int i = 0;i<s.size();++i)
        {
            if(v.find(i)!=v.end() && v[i]<k)
                continue;
            if(s[i]==p[u])
                u++;
            if(u==p.size())return 1;
        }
        return 0;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
      int l =0;
      int r =removable.size();
      int ans =l;
      map<int,int>v;
      for(int i = 0;i<removable.size();++i)v[removable[i]]=i;
        
     while(l<=r)
     {
         int m = (l+r)/2;
         if(check(m,s,p,v))
             l = m+1,ans = m;
         else
             r = m-1;
     }
    return ans;
    }
};