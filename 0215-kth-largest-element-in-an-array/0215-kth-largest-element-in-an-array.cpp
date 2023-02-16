class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto c:nums)
        {
            q.push(-c);
            if(q.size()>k)q.pop();
        }
        
        return -q.top();
    }
};

//1 2 5 