class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int>v(n+1);
        for(auto c:trust)
        {
            v[c[0]]--;
            v[c[1]]++;
        }
        for(int i = 1;i<n+1;++i)
            if(v[i]==n-1)
                return i;
        return -1;
        
    }
};