class Solution {
public:
    long long ans = 0;
    long long int dfs(int i,vector<vector<int>>&roads,int pre,int k)
    {
        long long int count =0;
        for(auto c:roads[i])
        {
            if(c!=pre)
            count+=dfs(c,roads,i,k);
        }
        if(i!=0)
        ans += (count+k)/k;
        return count+1;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>>v(roads.size()+1);
        for(auto c:roads)
            v[c[0]].push_back(c[1]),v[c[1]].push_back(c[0]);
        dfs(0,v,-1,seats);
       
        return  ans;
    }
};