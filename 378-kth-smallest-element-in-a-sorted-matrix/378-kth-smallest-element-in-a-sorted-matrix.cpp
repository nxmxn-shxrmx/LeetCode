class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>v;
        for(auto c:matrix)
        {
            for(auto z:c)
                v.push_back(z);
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};