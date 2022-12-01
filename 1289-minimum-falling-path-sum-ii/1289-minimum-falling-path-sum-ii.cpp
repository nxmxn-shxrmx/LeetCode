class Solution {
public:
    int minFallingPathSum(vector<vector<int>>&m) {
       
        vector<pair<int,int>>v(2,{INT_MAX,0});
        for(int i = 0;i<m.size();++i)
        {
            if(m[0][i]<=v[0].first)
            {
                v[1]=v[0];
                v[0].first=m[0][i];
                v[0].second=i;
            }
            else if(m[0][i]<v[1].first)
            {
                v[1].first=m[0][i];
                v[1].second=i;
            }
        }
    
        for(int i = 1;i<m.size();++i)
        {
            vector<pair<int,int>>q(2,{INT_MAX,0});
            for(int j=0;j<m.size();++j)
            {
                int p = INT_MAX;
                if(v[0].second!=j)
                    p = v[0].first;
                else
                    p = v[1].first;
                m[i][j]+=p;

                if(m[i][j]<=q[0].first)
                {
                q[1]=q[0];
                    q[0].first=m[i][j];
                    q[0].second=j;
                }
                else if(m[i][j]<=q[1].first)
                {
                    q[1].first=m[i][j];
                    q[1].second=j;
                }
             
            }
              v[0]=q[0];
            v[1]=q[1];
            
        }
        // for(auto c:m)
        // {
        //     for(auto x:c)
        //         cout<<x<<" ";
        //     cout<<"\n";
        // }
        return  v[0].first;
    }
};