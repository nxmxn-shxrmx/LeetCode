class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
       int ans =  v[0]+v[1]-1;
       int p = v[0]-2;
        if(v[1]>v[0])
            p = v[1]-1;
        for(int i=2;i<v.size();++i)
        {
            ans = max(ans,p+v[i]);
            if(p<v[i])
                p = v[i];
            p--;
        }
        return ans;
            
    }
};