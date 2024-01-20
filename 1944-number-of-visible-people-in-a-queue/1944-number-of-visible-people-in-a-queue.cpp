class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>s;
        vector<int>ans(heights.size());
        s.push(heights.size()-1);
        for(int i = heights.size()-2;~i;--i)
        {
            int ct = 0;
            while(!s.empty()&&heights[s.top()]<heights[i])
                s.pop(),ct++;
            if(!s.empty())ct++;
            s.push(i);
            ans[i]=ct;
        }
        return ans;
    }
};