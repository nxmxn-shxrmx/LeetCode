class Solution {
public:
  
    int minimumTotal(vector<vector<int>>& t) {
            
        for(int i = 1;i<t.size();++i)
        {
            t[i][0]+=t[i-1][0];
            for(int j =1;j<t[i-1].size();++j)
                t[i][j]=min(t[i-1][j-1],t[i-1][j])+t[i][j];
            t[i][t[i-1].size()]+=t[i-1][t[i-1].size()-1];
        }
        int ans = INT_MAX;
        for(auto c:t)
        {
            for(auto x:c)
                cout<<x<<" ";
            cout<<"\n";
        }
        for(auto c:t[t.size()-1])
            ans = min(ans,c);
        return ans;
    }
};