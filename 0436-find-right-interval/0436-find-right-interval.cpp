class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& inter) {
        vector<vector<int>>v;
        for(int i = 0;i<inter.size();++i)
            v.push_back({inter[i][0],inter[i][1],i});
        sort(v.begin(),v.end());
        vector<int>ans(v.size(),-1);
        for(int i = 0;i<v.size();++i)
        {
            int l  =0;
            int r = v.size()-1;
            int p  =-1;
            while(l<=r)
            {
                int m = (l+r)>>1;
                if(v[m][0]>=v[i][1])
                    r =  m-1,p = m;
                else l  = m +1; 
            }
            if(p!=-1)
            ans[v[i][2]]=v[p][2];
        }
        return ans;
    }
};