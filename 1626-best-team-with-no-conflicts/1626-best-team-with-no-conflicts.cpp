class Solution {
public:
   
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>v;
        int mx =0;
        for(int i = 0;i<scores.size();++i)
            v.push_back({scores[i],ages[i]}),mx = max(v[i][1],mx);
        sort(v.begin(),v.end());
        vector<int>pre(mx+1);
        vector<int>cur(mx+1);
        for(int i=v.size()-1;~i;--i)
        {
            for(int j =mx;~j;--j)
            {
                 int u =0;
                if(j<=v[i][1])
                u = pre[max(v[i][1],j)]+v[i][0];
                 cur[j]=max(pre[j],u); 

            }
            pre= cur;
        }
        return cur[0];
    }
};