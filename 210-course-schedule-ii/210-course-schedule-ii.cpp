class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre){
        
        vector<int>v(n);
        vector<vector<int>>g(n);
        for(auto c:pre)
        {
            v[c[0]]++;
            g[c[1]].push_back(c[0]);
        }

        queue<int>q;
        for(int i = 0;i<n;++i)
        {
            if(v[i]==0)
                q.push(i);
        //    cout<<v[i]<<"<-"<<i<<"\n";
        }
    
        
        vector<int>ans;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            
            ans.push_back(i);
            
            for(auto c:g[i])
            {
                v[c]--;
             //   cout<<c<<" "<<v[c]<<"\n";
                if(v[c]==0)
                {
                    q.push(c);
                }
            }
        }
        if(ans.size()==n)
            return ans;
        
        return {};
   }
};