class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       set<int>s;
       unordered_map<int,int>m;
       int ans = 0;
       int  ct = 0;
       for(int i = 0;i<fruits.size();++i)
       {
           if(m.size()==2&&m.find(fruits[i])==m.end())
           {
              
               m.erase(fruits[*s.begin()]);
                ct = *s.begin()+1;
               s.erase(*s.begin());
           }
           if(m.find(fruits[i])!=m.end())
               s.erase(m[fruits[i]]);
           m[fruits[i]]=i;
           s.insert(i);
           int p = i+1-ct;
          ans = max(ans,p);
       }
       // cout<<ct<<"\n";
        int p = fruits.size()-ct;
        ans = max(ans,p);
        return ans;
    }
};