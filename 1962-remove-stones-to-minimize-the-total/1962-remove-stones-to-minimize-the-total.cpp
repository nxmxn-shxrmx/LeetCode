class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
        for(auto c:piles)
            q.push(c);
        while(k--)
        {
            if(q.top()==0)
                break;
            int r = q.top();
            q.pop();
            r=(r+1)/2;
            q.push(r);
        }
        int l=0;
        while(!q.empty())
        {
            l+=q.top();
            q.pop();
        }
        return l;
    }
};
