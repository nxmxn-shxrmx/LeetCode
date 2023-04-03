class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ct = 0;
        sort(people.begin(),people.end());
        int i = 0;
        int j = people.size()-1;
        while(i<=j)
        {
            if(people[j]+people[i]<=limit)
            {
                ct++;
                ++i;
                --j;
            }
            else
                ct++,--j;
        }
        return ct;
    }
};