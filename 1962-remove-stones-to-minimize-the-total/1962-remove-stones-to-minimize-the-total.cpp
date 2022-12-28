class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
          int l=0;
        for(auto c:piles)
            q.push(c),l+=c;
        while(k--)
        {
            if(q.top()==0)
                break;
            int r = q.top();
            q.pop();
            l-=r/2;
            r=(r+1)/2;
            q.push(r);
        }

        return l;
    }
};
