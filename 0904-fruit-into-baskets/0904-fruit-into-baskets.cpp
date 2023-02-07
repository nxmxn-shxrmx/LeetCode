class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first=-1;
        int second=-1;
        int ct = 0;
        int ans = 0;
        for(int i = 0;i<fruits.size();++i)
        {
            if(first==-1)first=i;
            else if(second==-1 && fruits[i]!=fruits[first])second = i;
            else if(fruits[first]!=fruits[i]&&fruits[second]!=fruits[i])
            {
                if(first>=second)
                    swap(first,second);
                
                ct = first+1;
                first=i;
            }
            else if(fruits[first]==fruits[i])first=i;
            else if(fruits[second]==fruits[i])second=i;
            int p =i+1-ct;
            ans = max(ans,p);
            
        }
        int p = fruits.size()-ct;
        return max(ans,p);
    }
};