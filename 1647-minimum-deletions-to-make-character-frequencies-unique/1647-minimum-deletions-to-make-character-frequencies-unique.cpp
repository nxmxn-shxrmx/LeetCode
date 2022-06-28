class Solution {
public:
    int minDeletions(string s) {
        
        map<int,set<char>>m;
        map<char,int>u;
        for(auto c:s)
        {
            if(u[c]!=0)
            {
                m[u[c]].erase(c);
                u[c]++;
                m[u[c]].insert(c);
                
            }
            else 
                u[c]++,m[u[c]].insert(c);
        }
        int c=0;
        // for(auto c:m)
        // {
        //     cout<<c.first<<"->";
        //     for(auto x:c.second)
        //         cout<<x<<" ";
        //     cout<<"\n";
        // }
        for(auto it =m.rbegin();it!=m.rend();++it)
        {
            while(it->second.size()>1)
            {
                auto g = it->second.begin();
                if(it->first-1!=0)
                m[it->first-1].insert(*g);
                it->second.erase(*g);
                c++;
            }
            
        }
        return c;
        
    }
};