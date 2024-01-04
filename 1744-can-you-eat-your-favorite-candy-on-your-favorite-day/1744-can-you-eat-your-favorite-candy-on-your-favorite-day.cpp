class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
            vector<long long int>prefix(candiesCount.size()+1);
            for(int i = 0;i<candiesCount.size();++i)
                prefix[i+1]+=candiesCount[i]+prefix[i];
            vector<bool>ans;
            for(auto c:queries)
            {
                long long favDay = c[1]+1;
                long long favType = c[0];
                long long cap = c[2];
                
                if(prefix[favType]<favDay)
                {
                    if(prefix[favType]+candiesCount[favType]>=favDay)
                        ans.push_back(true);
                    else
                        ans.push_back(false);
                }
                else
                {
                    long long c = prefix[favType]/favDay+1;
                    if(cap>=c)ans.push_back(true);
                    else ans.push_back(false);
                }
            }
        return ans;
    }
};