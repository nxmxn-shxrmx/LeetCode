class Solution {
public:

    vector<int>s;
    Solution(vector<int>& nums) {
        s= {nums.begin(),nums.end()};
    }
    
    vector<int> reset() {
        return s;
    }
    
    vector<int> shuffle() {
        vector<int>g(s.begin(),s.end());
        for(int i = 0;i<s.size();++i)
        {
            int j  = rand()%s.size();
            swap(g[i],g[j]);
        }
        return g;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */