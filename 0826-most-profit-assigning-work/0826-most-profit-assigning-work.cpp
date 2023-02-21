class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>v;
        for(int i = 0;i<difficulty.size();++i)
            v.push_back({difficulty[i],profit[i]});
        sort(v.begin(),v.end());
        for(int i = 1;i<profit.size();++i)
            v[i].second = max(v[i].second,v[i-1].second);
        sort(worker.begin(),worker.end());
        int ans = 0;
        for(auto c:worker)
        {
            int l =0;
            int r = v.size()-1;
            int p = -1;
            while(l<=r)
            {
                int m = (l+r)/2;
                if(v[m].first<=c)
                    l = m+1,p =m;
                else r = m-1;
            }
            if(p!=-1)
            ans+=v[p].second;
        }
        return ans;
    }
};