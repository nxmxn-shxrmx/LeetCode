class Solution {
public:
    int threeSumClosest(vector<int>& n, int t) {
        long long y = INT_MAX;
        long long sum = 0;
        
        sort(n.begin(),n.end());
        for(int i = 0;i<n.size();++i)
        {
            long long h = n[i];
            int j = i+1;
            int k =n.size()-1;
            while(j<k)
            {
                long long g = h+n[j]+n[k];
                if(abs(g-t)<y)
                {
                    sum=g;
                    y = abs(g-t);
                }
                if(g>t)
                --k;
                else
                    ++j;
            }
        }
        return sum;
    }
};