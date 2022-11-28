class Solution {
public:
    int f(int a,int b,int c,int d,int e,int g)
    {
         return (g-d)*(c-a) - (d-b)*(e-c);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& t) {
        if(t.size()<=3)
            return t;
        sort(t.begin(),t.end());
        vector<vector<int>>u;
         vector<vector<int>>l;
        for(int i = 0;i<t.size();++i)
        {
            while(u.size()>1 && f(u[u.size()-2][0],u[u.size()-2][1],u[u.size()-1][0],u[u.size()-1][1],t[i][0],t[i][1])<0)
            u.pop_back();
            
             while(l.size()>1 && (f(l[l.size()-2][0],l[l.size()-2][1],l[l.size()-1][0],l[l.size()-1][1],t[i][0],t[i][1]))>0)
                l.pop_back();
        
                l.push_back(t[i]);
                u.push_back(t[i]);
        }
       
      
        set<vector<int>>s;
        for(auto c:l)
            s.insert(c);
        for(auto c:u)
            s.insert(c);
        
        return {s.begin(),s.end()};
    }
};
//there are some cosquences of technology