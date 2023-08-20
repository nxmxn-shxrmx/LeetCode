class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>v(n);
        map<pair<int,int>,int>m;
        for(auto c:roads)
        {
            v[c[0]]++;
            v[c[1]]++;
            m[{c[0],c[1]}]=1;
            m[{c[1],c[0]}]=1;
        }
        vector<pair<int,int>>vp;
        for(int i =0;i<v.size();++i)
            vp.push_back({v[i],i});
        sort(vp.begin(),vp.end());
        
        int u= vp.back().first;
        u+= vp[vp.size()-2].first;
        if(vp.size()==1)return u;
        if(m[{vp.back().second,vp[vp.size()-2].second}])u--;
    
        int h =u;
        for(int i = vp.size()-1;i>=1;--i)
        {
            
            for(int j =i-1;~j;--j)
            {
                
                h = vp[i].first+vp[j].first;
                if(m[{vp[i].second,vp[j].second}])h--;
                if(h>u)u = h;
                
                else if(h<u)break;
            }
        }
        return u;
    }
};