class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans1(spells.size());
        sort(potions.begin(),potions.end());
        for(int i =0;i<spells.size();++i)
        {
            long long u = spells[i];
            int l = 0;
            int r = potions.size()-1;
            int ans = r+1;
            while(l<=r)
            {
                int m = (l+r)/2;
                long long p = u*potions[m];
                if(p>=success)
                    ans = m,r=m-1;
                else l = m+1;
            }
            ans1[i] = potions.size()-ans;
            
        }
        return ans1;
    }
};